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
    void parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp) {
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            TreeNode* current = qu.front();
            qu.pop();
            if (current->left) {
                mp[current->left] = current;
                qu.push(current->left);
            }
            if (current->right) {
                mp[current->right] = current;
                qu.push(current->right);
            }
        }
    }
TreeNode* find(TreeNode* root, int start) {
    if (root == NULL) return NULL;

    if (root->val == start) return root;

    TreeNode* left = find(root->left, start);
    if (left != NULL) return left;

    return find(root->right, start);
}


    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> mp;
        parent(root, mp);
        TreeNode* target = find(root, start);
        unordered_map<int, bool> visited;
        queue<TreeNode*> qu;
        qu.push(target);
        visited[start] = true;
        int ans = 0;
        while (!qu.empty()) {
         
            int size = qu.size();
            for (int i = 0; i < size; i++) {
                TreeNode* current = qu.front();
                qu.pop();
                if (current->left && !visited[current->left->val]) {
                    qu.push(current->left);
                    visited[current->left->val] = true;
                }
                if (current->right && !visited[current->right->val]) {
                    qu.push(current->right);
                    visited[current->right->val] = true;
                }
                if (mp[current] && !visited[mp[current]->val]) {
                    qu.push(mp[current]);
                    visited[mp[current]->val] = true;
                }
            }
               ans++;
        }
        if(ans==0) return 0;
        return ans -1;
    }
};