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

    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return  1+ max(height(root->left),height(root->right));
    }

    void levelOrder(TreeNode* root,int curr,int target,vector<int>&ans){
        if(root==NULL) return ;
        if(curr==target){
            if (ans.size() == target)
                ans.push_back(root->val);
            return;
        }
        levelOrder(root->right,curr+1,target,ans);
        levelOrder(root->left,curr+1,target,ans);

    }

    vector<int> rightSideView(TreeNode* root) {
     int h = height(root);
     vector<int>ans;
     for(int i=0;i<h;i++){
        levelOrder(root,0,i,ans);
     }   
     return ans;
    }
};