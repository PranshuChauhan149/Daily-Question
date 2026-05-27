class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {
        int n = nums1.size();

        unordered_map<long long, long long> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int d = nums1[i] + nums2[j];
                mp[d]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum = nums3[i] + nums4[j];
                int d = (0 - sum);
                if (mp.find(d) != mp.end()) {
                    ans += mp[d];
                }
            }
        }

        return ans;
    }
};