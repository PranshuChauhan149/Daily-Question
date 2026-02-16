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
        if(root==NULL) return NULL;
        queue<Node*>qu;
        qu.push(root);
        while(!qu.empty()){
            int size = qu.size();
            Node* curr = qu.front();
            qu.pop();
            if (curr->left) qu.push(curr->left);
            if (curr->right) qu.push(curr->right);
            for(int i=1;i<size;i++){
                Node* sec = qu.front();
                qu.pop();
                curr->next = sec;
                curr = sec;
                if(sec->left){
                    qu.push(sec->left);
                }
                if(sec->right){
                    qu.push(sec->right);
                }
            }
            curr->next = NULL;
        
        }
        return root;
    }
};