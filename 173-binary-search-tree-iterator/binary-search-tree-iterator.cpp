/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int>inOrder;
    void inOrd(TreeNode* root){
        if(root==NULL){
            return;
        }
        inOrd(root->left);
        inOrder.push_back(root->val);
        inOrd(root->right);
    }
    int i = 0;

    BSTIterator(TreeNode* root) {
        inOrd(root);
    }
    
    
    int next() {
        int ans = inOrder[i];
        i++;
        return ans;        
    }
    
    bool hasNext() {
         if(i<inOrder.size()){
            return true;

        }
        else{
            return false;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */