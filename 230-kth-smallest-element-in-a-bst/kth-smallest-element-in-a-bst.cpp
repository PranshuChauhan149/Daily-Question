class Solution {
public:
    int kthElement(TreeNode* root, int &k){
        if(root == NULL) return -1;

        // search in left subtree
        int left = kthElement(root->left, k);
        if(left != -1) return left;

        // visit current node
        k--;
        if(k == 0) return root->val;

        // search in right subtree
        return kthElement(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        return kthElement(root, k);
    }
};
