/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr or head-> next == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* ne = head;
        while(ne != nullptr)
        {
            ListNode* temp1 = ne -> next;
            ne -> next = prev;
            prev = ne;
            ne = temp1;
        }
        return prev;
    }
};