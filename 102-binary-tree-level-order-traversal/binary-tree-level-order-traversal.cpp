
class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    void levelOrderTra(TreeNode* root, int curr, int target,
                       vector<vector<int>>& ans, vector<int>& a) {

        if (root == NULL) {
            return;
        }
        if (curr == target) {
            a.push_back(root->val);
        }
        levelOrderTra(root->left, curr + 1, target, ans, a);
        levelOrderTra(root->right, curr + 1, target, ans, a);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        int h = height(root);
        vector<vector<int>> ans;
        for (int i = 0; i < h; i++) {
            vector<int> a;
            levelOrderTra(root, 0, i, ans, a);
            ans.push_back(a);
        }
        return ans;
    }
};