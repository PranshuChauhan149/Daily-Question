class Solution {
public:
    int f(vector<int>& nums, int i,vector<int>&dp) {
        if (i == nums.size() - 1)
            return 0;
        if (nums[i] == 0)
            return 1e9;
    if(dp[i]!=-1) return dp[i];
        int idx = nums[i];
        int ans = INT_MAX;
        for (int k = 1; k <= idx; k++) {

            if (i + k < nums.size()) {
                ans = dp[i] =  min(ans, 1 + f(nums, i + k,dp));
            }
        }
        return dp[i] =   ans;
    }

    int jump(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
         return f(nums, 0,dp); }
};