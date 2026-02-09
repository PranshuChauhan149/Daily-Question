/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mp){
        queue<TreeNode*>qu;
        qu.push(root);
        while(!qu.empty()){
            TreeNode* curr = qu.front();
            qu.pop();
            if(curr->left){
                mp[curr->left] = curr;
                qu.push(curr->left);
            }
            if(curr->right){
                mp[curr->right] = curr;
                qu.push(curr->right);
            }
        }
    }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mp;
        parent(root,mp);
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>qu;
        qu.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!qu.empty()){
            if(curr_level++==k) break;
            int size = qu.size();
            for(int i=0;i<size;i++){
                TreeNode* current = qu.front();
                qu.pop();
                if(current->left!=NULL && !visited[current->left]){
                    qu.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right!=NULL && !visited[current->right]){
                    qu.push(current->right);
                    visited[current->right] = true;
                }
                if(mp[current] && !visited[mp[current]]){
                    qu.push(mp[current]);
                    visited[mp[current]] = true;
                }
            }

        }
        vector<int>ans;
        while(!qu.empty()){
            TreeNode* curr = qu.front();
            qu.pop();
            ans.push_back(curr->val);
        }
        return ans;

    }
};