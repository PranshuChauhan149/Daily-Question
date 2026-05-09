class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();

        int layers = min(n, m) / 2;

        for (int layer = 0; layer < layers; layer++) {

            vector<int> nums;

            int top = layer;
            int bottom = n - layer - 1;
            int left = layer;
            int right = m - layer - 1;

            for (int j = left; j <= right; j++) {
                nums.push_back(grid[top][j]);
            }

            for (int i = top + 1; i <= bottom - 1; i++) {
                nums.push_back(grid[i][right]);
            }

            for (int j = right; j >= left; j--) {
                nums.push_back(grid[bottom][j]);
            }

            for (int i = bottom - 1; i >= top + 1; i--) {
                nums.push_back(grid[i][left]);
            }

            int len = nums.size();
            int normalized = k % len;

            rotate(nums.begin(), nums.begin() + normalized, nums.end());

            int idx = 0;

            for (int j = left; j <= right; j++) {
                grid[top][j] = nums[idx++];
            }

            for (int i = top + 1; i <= bottom - 1; i++) {
                grid[i][right] = nums[idx++];
            }

            for (int j = right; j >= left; j--) {
                grid[bottom][j] = nums[idx++];
            }

            for (int i = bottom - 1; i >= top + 1; i--) {
                grid[i][left] = nums[idx++];
            }
        }

        return grid;
    }
};