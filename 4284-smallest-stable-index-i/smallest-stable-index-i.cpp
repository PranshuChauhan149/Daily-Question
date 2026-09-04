class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mi(n, 0);
        vector<int> ma(n, 0);
        int m = INT_MIN;
        for (int i = 0; i < n; i++) {
            m = max(m, nums[i]);
            mi[i] = m;
        }
        int mm = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            mm = min(mm, nums[i]);
            ma[i] = mm;
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            int a = mi[i] - ma[i];
            if (a <= k) {
                return i;
                count++;
            }
        }
        return count == 0 ? -1 : 0;
    }
};