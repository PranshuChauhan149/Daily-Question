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
        if(root==NULL) return 0;
        return 1 + max(height(root->left),height(root->right));
    }

    void levelOrder(TreeNode* root,vector<int>&a,int curr,int target){
        if(root==NULL) return ;
        if(curr==target){
            a.push_back(root->val);
        }
            if(target%2==0){
                levelOrder(root->left,a,curr+1,target);
                levelOrder(root->right,a,curr+1,target);
            }
            else{
                 levelOrder(root->right,a,curr+1,target);
                levelOrder(root->left,a,curr+1,target);
            }
        
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int h = height(root);
        vector<vector<int>>ans;
        for(int i=0;i<h;i++){
            vector<int>a;
            levelOrder(root,a,0,i);
            ans.push_back(a);
        }
        return ans;
    }
};