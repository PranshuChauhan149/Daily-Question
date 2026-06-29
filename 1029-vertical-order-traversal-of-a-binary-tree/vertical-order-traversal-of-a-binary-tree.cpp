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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>qu;
        qu.push({root,{0,0}});
        while(!qu.empty()){
            auto ele = qu.front();
            qu.pop();
            TreeNode* curr = ele.first;
            int a = ele.second.first;
            int b = ele.second.second;
           
            mp[a][b].insert(curr->val);
            if(curr->left){
                 qu.push({curr->left, {a - 1, b + 1}});
            }
            if(curr->right){
                 qu.push({curr->right, {a + 1, b + 1}});
            }
        }
         vector<vector<int>>ans;
       for (auto &p : mp) {
            vector<int> col;
            for (auto &q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};