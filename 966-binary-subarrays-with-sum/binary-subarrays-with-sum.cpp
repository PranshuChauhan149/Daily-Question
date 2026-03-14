class Solution {
public:

    int find(vector<int>&nums,int goal){
        if(goal < 0) return 0;
        int count = 0;
        int n = nums.size();
        int sum =0;
        int i = 0;
        int j = 0;
        while(j < n){
            count += nums[j];
            while(count > goal){
                count -= nums[i];
                i++;
            }
            sum += (j-i+1);
            j++;
        }
        return sum;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int a = find(nums,goal);
        int b = find(nums,goal-1);
        return a-b;
    }
};