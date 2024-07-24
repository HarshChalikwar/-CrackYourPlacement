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
    bool isPalindrome(ListNode* head) {
        ListNode* s = head;
        ListNode* f= head;
        ListNode* prev = nullptr;
        while(f != nullptr and f->next != nullptr)
        {
            f = f->next->next;
            ListNode* temp = s-> next;
            s -> next = prev;
            prev = s;
            s = temp;
        }
        if(f != nullptr)
        {
            s= s-> next;
        }
        while(prev!=nullptr and s != nullptr)
        {
            if(prev->val != s->val)
            {
                return false;
            }
            prev = prev -> next;
            s = s-> next;
        }
        return true;
    }
};