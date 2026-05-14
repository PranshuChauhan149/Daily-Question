class Solution {
public:
    void f(vector<int>& candidates, int i, vector<int>& a,
           vector<vector<int>>& ans, int target) {
        if (i>=candidates.size())
            return;
        if (target == 0) {
            ans.push_back(a);
            return;
        }

        if (candidates[i] <= target) {
            a.push_back(candidates[i]);
            f(candidates, i, a, ans, target - candidates[i]);
            a.pop_back();
        }
        f(candidates, i+1, a, ans, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> a;
        vector<vector<int>> ans;
        int n = candidates.size();
        f(candidates, 0, a, ans, target);
        return ans;
    }
};