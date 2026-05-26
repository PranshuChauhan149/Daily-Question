class Solution {
public:
    void f(vector<int>& nums, int i, vector<int>& a, vector<vector<int>>& ans) {
        if (i >= nums.size()) {
            ans.push_back(a);
            return;
        }
        a.push_back(nums[i]);
        f(nums, i + 1, a, ans);
        a.pop_back();
        f(nums, i + 1, a, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> a;
        vector<vector<int>> ans;
        f(nums, 0, a, ans);
        return ans;
    }
};