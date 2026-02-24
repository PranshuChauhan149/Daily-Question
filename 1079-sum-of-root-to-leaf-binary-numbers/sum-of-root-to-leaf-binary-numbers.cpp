
class Solution {
public:
    int find(string s) {
        int n = s.size();
        int sum = 0;
        for (int k = 0; k < s.size(); k++) {
            if(s[k]=='1') sum += pow(2, n - 1 - k);
        }
        return sum;
    }

    void f(TreeNode* root, vector<string>& ans, string s) {
        if (root == NULL)
            return;
        string ss = to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(s + ss);
            return;
        }
        f(root->left, ans, s + ss);
        f(root->right, ans, s + ss);
    }

    int sumRootToLeaf(TreeNode* root) {
        vector<string> ans;
        string str = "";
        f(root, ans, str);
        int sum = 0;
        int a = 0;
        for (int i = 0; i < ans.size(); i++) {
            
            a += find(ans[i]);
        }
        return a;
    }
};