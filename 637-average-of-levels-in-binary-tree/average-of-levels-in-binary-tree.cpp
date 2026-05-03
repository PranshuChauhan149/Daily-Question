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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        vector<double> ans;
        while (!qu.empty()) {
            int s = qu.size();
            double sum = 0;
            for (int i = 0; i < s; i++) {
                auto a = qu.front();
                double v = a->val;
                sum += v;
                qu.pop();
                if (a->left) {
                    qu.push(a->left);
                }
                if (a->right) {
                    qu.push(a->right);
                }
            }
            double avg = sum / s;
            ans.push_back(avg);
        }
        return ans;
    }
};