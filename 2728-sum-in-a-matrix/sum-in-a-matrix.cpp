class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int r = nums.size();
        int c = nums[0].size();
        for (int i = 0; i < r; i++) {
            sort(nums[i].begin(), nums[i].end(), greater<int>());
        }
        int ans = 0;
        for (int i = 0; i < c; i++) {
            int a = -1;
            for (int j = 0; j < r; j++) {
                a = max(a,nums[j][i]);
            }
            ans += a;
        }
        return ans;
    }
};