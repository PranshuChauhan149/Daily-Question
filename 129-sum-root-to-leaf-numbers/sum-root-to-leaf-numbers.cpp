
class Solution {
public:


    void f(TreeNode* root,int &sum,int curr){
        if(root==NULL) return ;
        curr = curr * 10 + root->val;
        if(root->left == NULL && root->right==NULL){
            sum += curr;
        }
        f(root->left,sum,curr);
        f(root->right,sum,curr);
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        f(root,ans,0);
        return ans;
    }
};