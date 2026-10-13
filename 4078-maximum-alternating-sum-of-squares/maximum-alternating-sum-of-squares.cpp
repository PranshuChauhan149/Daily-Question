class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n  = nums.size();
        for(int i = 0;i<n;i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = n-1;
        long long ans = 0;
        while(i < j){
             ans += (pow(nums[j],2) - pow(nums[i],2));
             i++;
             j--;
        }
        if(n % 2 != 0){
            ans+= pow(nums[n/2],2);
        }
        return ans;
    }
};