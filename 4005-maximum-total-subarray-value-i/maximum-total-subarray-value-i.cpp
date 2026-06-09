class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mi = INT_MAX;
        long long ma = INT_MIN;
        int n = nums.size();
        for(int i =0;i<n;i++){
            mi = min(mi,(long long)nums[i]);
            ma = max(ma,(long long)nums[i]);
        }
        long long ans = (ma - mi) * k;
        return ans;
    }
};