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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = new ListNode(-101);
        ListNode* temp = head;
        while(temp != nullptr)
        {
            if(temp -> val == prev -> val)
            {
                prev -> next = temp -> next;
                temp = prev -> next;
            }
            else
            {
                prev = temp;
                temp = temp -> next;
            }
        }
        return head;
    }
};