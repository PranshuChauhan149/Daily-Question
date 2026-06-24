class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k)
            return 0;

        double sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        double ans = sum / k;
        int j = k;
        int i = 0;

        while (j < n) {
            sum -= nums[i++];
            sum += nums[j++];
            ans = max(ans,sum / k);
        }
        return ans;
    }
};