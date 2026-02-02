class Solution {
public:
    int ans = INT_MIN;

    int leftRoot(TreeNode* root) {
        if (root == NULL) return 0;
        return max(0, root->val +
                   max(leftRoot(root->left), leftRoot(root->right)));
    }

    int rightRoot(TreeNode* root) {
        if (root == NULL) return 0;
        return max(0, root->val +
                   max(rightRoot(root->left), rightRoot(root->right)));
    }

    void f(TreeNode* root) {
        if (root == NULL) return;

        int left = leftRoot(root->left);
        int right = rightRoot(root->right);

        ans = max(ans, root->val);
        ans = max(ans, root->val + left);
        ans = max(ans, root->val + right);
        ans = max(ans, root->val + left + right);

        f(root->left);
        f(root->right);
    }

    int maxPathSum(TreeNode* root) {
        f(root);
        return ans;
    }
};
