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
    TreeNode* f(vector<int>& inorder, int inLow, int inHigh,
                vector<int>& postorder, int posHigh, int posLow) {
        if (posLow > posHigh) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[posHigh]);
        if (posHigh == posLow)
            return root;
        int i = inLow;
        while (i <= inHigh) {
            if (inorder[i] == postorder[posHigh]) {
                break;
            }
            i++;
        }
        root->left = f(inorder, inLow, i , postorder, posLow + (i-inLow -1),
                       posLow);
        root->right = f(inorder, i + 1, inHigh, postorder,
                        posHigh - 1, posLow +(i-inLow));
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return f(inorder, 0, n - 1, postorder, n - 1, 0);
    }
};