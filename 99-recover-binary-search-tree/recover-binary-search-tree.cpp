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

    void inOrder(TreeNode* root,vector<int>&ans){
        if(root==NULL) return;
        inOrder(root->left,ans);
        ans.push_back(root->val);
        inOrder(root->right,ans);
    }
    void iOrder(TreeNode* root,vector<int>&ans,int &i){
        if(root==NULL) return;
        iOrder(root->left,ans,i);
        root->val = ans[i++];
        iOrder(root->right,ans,i);
    }

    void recoverTree(TreeNode* root) {
        vector<int>ans;
        inOrder(root,ans);
        sort(ans.begin(),ans.end());
        int i=0;
        iOrder(root,ans,i);
    }
};