/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* make(int l, int r, vector<int>& ans) {
        if (l > r)
            return NULL;
         int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(ans[mid]);
        root->left = make(l, mid - 1, ans);
        root->right = make(mid + 1, r, ans);
        return root;
    }

    void inOrder(TreeNode* root, vector<int>& ans) {
        if (root == NULL)
            return ;
        inOrder(root->left, ans);
        ans.push_back(root->val);
        inOrder(root->right, ans);
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inOrder(root, ans);
        return make(0,ans.size()-1,ans);

    }
};