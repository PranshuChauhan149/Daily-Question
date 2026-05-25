class Solution {
public:
    void f(vector<int>& candidates, int i, int target, vector<int>& a,
           vector<vector<int>>& ans) {
        int n = candidates.size();
        if (target == 0) {
            ans.push_back(a);
            return;
        }
        if (i >= n)
            return;

        if (candidates[i] <= target) {
            a.push_back(candidates[i]);
            f(candidates, i, target - candidates[i], a, ans);
            a.pop_back();
        }
        f(candidates, i + 1, target, a, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> a;
        f(candidates, 0, target, a, ans);
        return ans;
    }
};