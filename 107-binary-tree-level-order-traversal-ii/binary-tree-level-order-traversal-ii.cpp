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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> e;
        if (root == NULL)
            return e;
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            int size = qu.size();
            vector<int> a;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = qu.front();
                a.push_back(curr->val);
                qu.pop();
                if (curr->left) {
                    qu.push(curr->left);
                }
                if (curr->right) {
                    qu.push(curr->right);
                }
            }
            e.push_back(a);
        }
        vector<vector<int>> ans;
        int r = e.size();
        for (int i = r - 1; i >= 0; i--) {
            ans.push_back(e[i]);
        }
        return ans;
    }
};