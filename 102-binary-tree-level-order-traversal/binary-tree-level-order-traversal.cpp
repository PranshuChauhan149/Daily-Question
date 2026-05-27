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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> qu;
        qu.push(root);
        vector<vector<int>> ans;
        while (!qu.empty()) {
            int size = qu.size();
            vector<int> a;
            while (size--) {
                auto ele = qu.front();
                qu.pop();
                a.push_back(ele->val);
                if (ele->left) {
                    qu.push(ele->left);
                }
                if (ele->right) {
                    qu.push(ele->right);
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};