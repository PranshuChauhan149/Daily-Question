class Solution {
public:

    long long f(vector<int>&nums,vector<int>&colors,int i,vector<long long>&dp){
        if(i==0) return nums[i];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        long long skip = 0 + f(nums,colors,i-1,dp);
        long long take  = 0;
        if(colors[i]==colors[i-1]){
            take = nums[i] + f(nums,colors,i-2,dp);
        }
        else{
            take = nums[i] + f(nums,colors,i-1,dp);
        }
        return dp[i] = max(skip,take);
    }

    long long rob(vector<int>& nums, vector<int>& colors) {
        vector<long long >dp(nums.size()+1,-1);
        return f(nums,colors,nums.size()-1,dp);
    }
};