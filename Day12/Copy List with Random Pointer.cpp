/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> m;
        Node* node = head;
        Node* node2 = new Node(-1);
        Node* head2 = node2;
        while(node != nullptr)
        {
            Node* temp = new Node(node->val);
            node2 -> next = temp;
            m[node] = temp;
            node2 = node2 -> next;
            node = node -> next;
        }
        node = head;
        while(node != nullptr)
        {
            if(node -> random != nullptr)
            m[node]->random = m[node -> random];
            else m[node]->random = nullptr;
            node = node -> next;
        }
        return head2->next;
    }
};