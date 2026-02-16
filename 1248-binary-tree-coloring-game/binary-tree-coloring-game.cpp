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


  int subTree(TreeNode* root){
    if(root==NULL) return 0;
    
    return 1 +subTree(root->left) + subTree(root->right);
}


    TreeNode* find(TreeNode* root,int x){
        if(root==NULL) return NULL;
        if(root->val==x){
            return root;
        }
        TreeNode* d = find(root->left,x);
        if(d) return d;
        return find(root->right,x);
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* target = find(root,x);

       int l = subTree(target->left);
       int r = subTree(target->right);
        int p = n - (l+r+1);

        int ma = max({l,r,p});
       return ma > n/2;
        



    }
};