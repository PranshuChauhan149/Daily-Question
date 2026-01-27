class Solution {
public:

    void f(vector<int>&nums,int i,vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(nums);
            return ;
        }
        for(int idx = i;idx<nums.size();idx++){
            swap(nums[idx],nums[i]);
            f(nums,i+1,ans);
            swap(nums[idx],nums[i]);

        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        f(nums,0,ans);
        return ans;
    }
};