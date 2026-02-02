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

    int height(TreeNode* p, TreeNode* q){
        if(p==NULL && q!=NULL) return -1;
        if(q==NULL && p!=NULL) return -1;
        if(p==NULL || q==NULL) return 0;
        if(p->val!=q->val){
            return -1;
        }
        int left = height(p->left,q->left);
        if(left==-1) return -1;
        int right = height(p->right,q->right);
        if(right==-1) return -1;
        return p->val + max(left,right);
        
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(height(p,q)==-1) return false;
        return true;
    }
};