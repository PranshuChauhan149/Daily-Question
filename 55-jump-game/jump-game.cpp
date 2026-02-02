class Solution {
public:

    bool f(vector<int>&nums,int i,vector<int>&dp){
        if(i>=nums.size()-1) return true;
        if(nums[i]==0) return false;        

        if(dp[i]!=-1) return dp[i];
        int idx = nums[i];
        for(int k = 1;k<=idx;k++){
            if(f(nums,i+k,dp)){
               return  dp[i] = true;
            }
        }
        return dp[i] = false;

    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1 &&  nums[0]==0) return true;
        vector<int>dp(nums.size()+1,-1);
        return f(nums,0,dp);
    }
};