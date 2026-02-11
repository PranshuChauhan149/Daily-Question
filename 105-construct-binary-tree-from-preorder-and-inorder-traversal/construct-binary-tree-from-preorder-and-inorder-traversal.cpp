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
    TreeNode* f(vector<int>& preorder, int preLow, int preHigh,
                vector<int>& inorder, int inLow, int inHigh) {
        if (preLow > preHigh)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preLow]);
        if (preLow == preHigh)
            return root;
        int i = inLow;
        while (i <= inHigh) {
            if (preorder[preLow] == inorder[i]) {
                break;
            }
            i++;
        }

        root->left =
            f(preorder, preLow + 1, preLow+(i - inLow), inorder, inLow, i - 1);
        root->right =
            f(preorder, preLow+(i - inLow) + 1, preHigh, inorder, i + 1, inHigh);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return f(preorder, 0, n - 1, inorder, 0, n - 1);
    }
};