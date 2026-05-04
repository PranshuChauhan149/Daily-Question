class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<long long> pre(n, 0);
        long long sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            pre[i] = sum;
        }

        vector<long long> ans;

        for (auto q : queries) {
            int idx = lower_bound(nums.begin(), nums.end(), q) - nums.begin();

            long long leftCount = idx;
            long long leftSum = (idx > 0) ? pre[idx - 1] : 0;
            long long costLeft = (long long)q * leftCount - leftSum;

            long long rightCount = n - idx;
            long long rightSum = pre[n - 1] - leftSum;
            long long costRight = rightSum - (long long)q * rightCount;

            ans.push_back(costLeft + costRight);
        }

        return ans;
    }
};