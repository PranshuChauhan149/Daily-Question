class Solution {
public:
    bool f(vector<int>& nums, int idx, vector<int>& dp) {
        if (idx == nums.size() - 1)
            return true;

        if (nums[idx] == 0)
            return false;
        int d = nums[idx];
        if (dp[idx] != -1)
            return dp[idx];
        for (int i = idx; i < d + idx; i++) {
            if (f(nums, i + 1, dp))
                return dp[idx] = true;
        }
        return dp[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return f(nums, 0, dp);
    }
};