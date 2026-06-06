class Solution {
public:
    void f(TreeNode* root, int targetSum, int sum, vector<int>& a,
           vector<vector<int>>& ans) {
        if (root == NULL) {
            return;
        }
        sum += root->val;
        a.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum)
                ans.push_back(a);
        }

        f(root->left, targetSum, sum, a, ans);
        f(root->right, targetSum, sum, a, ans);

        a.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> a;
        int sum = 0;
        f(root, targetSum, sum, a, ans);
        return ans;
    }
};