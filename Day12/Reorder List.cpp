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
    ListNode* revers(ListNode* head)
    {
        ListNode* node = head;
        ListNode* prev = nullptr;
        while(node != nullptr)
        {
            ListNode* temp = node -> next;
            node -> next = prev;
            prev = node;
            node = temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* f = head;
        ListNode* s = head;
        while(f->next != nullptr and f->next->next != nullptr)
        {
            f = f->next->next;
            s= s->next;
        }
        ListNode* head2 = revers(s->next);
        s->next = nullptr;
        while(head!= nullptr and head2!= nullptr)
        {
            ListNode* temp = head2;
            head2 = head2 -> next;
            temp -> next = head -> next;
            head -> next = temp;
            head = head->next->next;
        } 
    }
};