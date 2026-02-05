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

    void f(TreeNode* root,vector<string>&ans,string s){
        if(root==NULL) return ;
        string  c = to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            s+=c;
            ans.push_back(s);
        }
        f(root->left,ans,s+c+"->");
        f(root->right,ans,s+c+"->");
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string str;
        f(root,ans,str);
        return ans;
    }
};