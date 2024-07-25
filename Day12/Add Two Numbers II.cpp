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
        ListNode* prev = nullptr;
        while(head != nullptr)
        {
            ListNode* temp = head -> next;
            head -> next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = revers(l1);
        l2 = revers(l2);
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        int car = 0;
        ListNode* l11 = l1;
        while(l1 != nullptr and l2!= nullptr)
        {
            int data = (l1 -> val + l2-> val+car)%10;
            car = (l1 -> val + l2-> val+car)/10;
            l1 -> val = data;
            l2 -> val = data;
            if(l1 -> next== nullptr and l2 -> next == nullptr)
            {
                l11 = l1;
            }
            l1 = l1 -> next;
            l2 = l2  -> next;
        }
        while(l1 != nullptr)
        {
            int data = (l1 -> val +car)%10;
            car = (l1 -> val +car)/10;
            l1 -> val = data;
            if(l1 -> next == nullptr) {if(car == 0){head1 = revers(head1);return head1;}
            else
            {
                ListNode* temp = new ListNode(car);
                l1 -> next = temp;
                head1 = revers(head1);return head1;
            }}
            
            l1 = l1 -> next;
        }
        while(l2 != nullptr)
        {
            int data = (l2-> val+car)%10;
            car = (l2-> val+car)/10;
            l2 -> val = data;
            if(l2 ->next ==  nullptr){if(car == 0){ head2 = revers(head2);return head2;}
            else
            {
                ListNode* temp = new ListNode(car);
                l2 -> next = temp;
                head2 = revers(head2);return head2;
            }
            }
            l2 = l2  -> next;
        }
        if(car == 0){head1 = revers(head1);return head1;}
            else
            {
                ListNode* temp = new ListNode(car);
                l11 -> next = temp;
                head1 = revers(head1);return head1;
            }
    }
};