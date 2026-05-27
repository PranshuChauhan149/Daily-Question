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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         if(root==NULL) return {};
        queue<TreeNode*> qu;
        qu.push(root);
        int i =0;
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
            i++;
            if(i%2==0){
                reverse(a.begin(),a.end());
            }

            ans.push_back(a);
        }
        return ans;
    }
};