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

    TreeNode* make(TreeNode* root,vector<int>&ans,int s,int e){
        if(e<s) return NULL;
        int mid = (s + e)/2;
        TreeNode* r = new TreeNode(ans[mid]);
        r->left = make(root,ans,s,mid-1);
        r->right = make(root,ans,mid+1,e);
        return r;

    }

    void inOrder(TreeNode* root,vector<int>&ans){
        if(root==NULL) return ;
        inOrder(root->left,ans);
        ans.push_back(root->val);
        inOrder(root->right,ans);
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>ans;
        inOrder(root,ans);
        return make(root,ans,0,ans.size()-1);

        
    }
};