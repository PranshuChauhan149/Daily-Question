/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
            return "";
        string s = "";
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            TreeNode* curr = qu.front();
            qu.pop();
            if (curr == NULL) {
                s += "#,";
            }

            else {
                s += to_string(curr->val) + ',';
            }
            if (curr != NULL) {
                qu.push(curr->left);
                qu.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0)
            return NULL;

        stringstream ss(data);
        string str;
        getline(ss, str, ',');
         TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            TreeNode* curr = qu.front();
            qu.pop();
            getline(ss, str, ',');
             if (str == "#") { curr->left = NULL; }
            else {
                TreeNode* l = new TreeNode(stoi(str));
                curr->left = l;
                qu.push(l);
            }
            getline(ss, str, ',');
             if (str == "#") { curr->right = NULL; }
            else {
                TreeNode* r = new TreeNode(stoi(str));
                curr->right = r;
                qu.push(r);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));