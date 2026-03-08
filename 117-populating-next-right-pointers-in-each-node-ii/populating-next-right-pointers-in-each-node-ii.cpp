/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return NULL;
        queue<Node*> qu;
        qu.push(root);
        while (!qu.empty()) {
            int size = qu.size();
            Node* first = qu.front();
            qu.pop();
            if (first->left)
                qu.push(first->left);
            if (first->right)
                qu.push(first->right);
            for (int i = 1; i < size; i++) {
                auto s = qu.front();
                first->next = s;
                first = s;
                qu.pop();
                if (s->left != NULL)
                    qu.push(s->left);
                if (s->right != NULL)
                    qu.push(s->right);
            }
            first->next = NULL;
        }
        return root;
    }
};