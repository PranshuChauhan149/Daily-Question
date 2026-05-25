class Solution {
public:
    set<vector<int>> st;
    void f(vector<int>& nums, int i, vector<vector<int>>& ans) {
        if (i >= nums.size()) {
            if (!st.count(nums)) {
                ans.push_back(nums);
                st.insert(nums);
            }
            return;
        }
        for (int idx = i; idx < nums.size(); idx++) {
            swap(nums[i], nums[idx]);
            f(nums, i + 1, ans);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        f(nums,0,ans);
        return ans;
    }
};