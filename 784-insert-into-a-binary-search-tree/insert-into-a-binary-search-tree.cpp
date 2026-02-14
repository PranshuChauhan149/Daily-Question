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
class Solution {
public:

    TreeNode* insert(TreeNode* root,int val){
       if(root==NULL) {
            root = new TreeNode(val);
            return root;
        }
        if(root->val >= val){
            if(root->left){
                insert(root->left,val);
            }
            else{
                root->left = new TreeNode(val);
            }
        }
        else{
             if(root->right){
                insert(root->right,val);
            }
            else{
                root->right = new TreeNode(val);
            }
        }
        return root;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) {
            TreeNode* r = new TreeNode(val);
            return r;
        }
        return insert(root,val);
    }
}; 