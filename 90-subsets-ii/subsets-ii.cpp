class Solution {
public:
    set<vector<int>> st;

    void f(vector<int>& nums, int i, vector<int>& a, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            if (!st.count(a)) {
                ans.push_back(a);
                st.insert(a);
            }
            return;
        }

        a.push_back(nums[i]);
        f(nums, i + 1, a, ans);
        a.pop_back();
        int idx = i + 1;
        while (idx > nums.size() && nums[idx] == nums[i])
            idx++;
        f(nums, idx, a, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> a;
        vector<vector<int>> ans;
        f(nums, 0, a, ans);
        return ans;
    }
};