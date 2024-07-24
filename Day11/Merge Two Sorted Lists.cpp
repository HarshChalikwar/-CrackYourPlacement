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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*j;
        ListNode* i = new ListNode();
        j = i;
        while(list1 != nullptr and list2 !=nullptr)
        {
            if(list1->val > list2->val)
            {
                i -> next = list2;
                list2 = list2 -> next;
            }
            else
            {
                i -> next = list1;
                list1 = list1 -> next;
            }
            i = i-> next;
        }
        if(list1 != nullptr) i -> next = list1;
        else i -> next = list2;
        return j-> next;
    }
};