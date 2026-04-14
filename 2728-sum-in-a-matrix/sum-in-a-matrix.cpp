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
            priority_queue<int> pq;
            for (int j = 0; j < r; j++) {
                pq.push(nums[j][i]);
            }
            ans += pq.top();
        }
        return ans;
    }
};