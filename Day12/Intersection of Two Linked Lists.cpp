/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n = 0;
        ListNode *h1 = headA;
        while(h1 -> next != nullptr)
        {
            n++;
            h1 = h1 -> next;
        }
        ListNode *h2 = headB;
        int m = 0;
        while(h2 -> next != nullptr)
        {
            m++;
            h2 = h2 -> next;
        }
        int k = abs(m-n);
        if(m>n)
        {
            while(k>0)
            {
                headB =  headB->next;
                k--;
            }
        }
        else
        {
            while(k>0)
            {
                headA =  headA->next;
                k--;
            }
        }
        while(headB != nullptr)
        {
            if(headA == headB) return headA;
            headB = headB->next;
            headA = headA -> next;
        }
        return nullptr;
    }
};