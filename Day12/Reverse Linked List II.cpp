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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int cnt = 1;
        ListNode* l1 = nullptr;
        ListNode* l2 = nullptr;
        ListNode* node = head;
        ListNode* end2 = nullptr;
        while(node != nullptr)
        {
            if(cnt == left -1)
            {
                end2 = node;
            }
            if(cnt == left)
            {
                l1 = node;
            }
            if(cnt == right)
            {
                l2 = node -> next;
                node -> next = nullptr;
            }
            node = node -> next;
            cnt++;
        }
        ListNode* end = l1;
        l1 = revers(l1);
        end -> next = l2;
        if(left == 1) return l1;
        else
        {
            end2 -> next = l1;
            return head;
        }
    }
};