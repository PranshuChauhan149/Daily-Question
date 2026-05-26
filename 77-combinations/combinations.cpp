class Solution {
public:
    void f(int n, int idx, int k, vector<vector<int>>& ans, vector<int>& a) {
        if (a.size() == k) {
            ans.push_back(a);
            return;
        }
        for (int i = idx; i <= n; i++) {
            a.push_back(i);
            f(n, i + 1, k, ans, a);
            a.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> a;
        vector<vector<int>> ans;
        f(n, 1, k, ans, a);
        return ans;
    }
};