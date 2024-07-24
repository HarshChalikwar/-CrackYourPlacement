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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = new ListNode(-1);
        ListNode* head2 = prev;
        ListNode* node = head;
        while(node != nullptr)
        {
            if(node-> val == val)
            {
                prev-> next = node -> next;
                node = node -> next;
            }
            else
            {
                prev -> next = node;
                prev = prev -> next;
                node = node->next;
            }
        }   
        return head2->next;
    }
};