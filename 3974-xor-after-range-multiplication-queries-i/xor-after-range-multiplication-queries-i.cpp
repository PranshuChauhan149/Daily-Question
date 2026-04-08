class Solution {
public:
static const int mod = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int r = queries.size();
        for (int i = 0; i < r; i++) {
            long long idx = queries[i][0];
            int r = queries[i][1];
            while (idx <= r) {
                nums[idx] = 1ll * nums[idx] * queries[i][3] % mod ;
                idx += queries[i][2];
            }
        }
        int a = 0;
        for (int i = 0; i < nums.size(); i++) {
            a ^= nums[i];
        }
        return a;
    }
};