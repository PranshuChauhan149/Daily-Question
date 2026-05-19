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
        if (head == NULL)
            return NULL;
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        unordered_map<Node*, Node*> mp;
        Node* t = head;
        while (t) {
            int d = t->val;
            Node* f = new Node(d);
            temp->next = f;
            mp[t] = f;
            temp = temp->next;
            t = t->next;
        }
        t = head;
        temp = dummy->next;
        while (t) {
            Node* r = t->random;
            if (r != NULL) {
                temp->random = mp[r];
            } else {
                temp->random = NULL;
            }

            t = t->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};