class Solution {
public:
    int f(vector<vector<int>>& grid, int k, int i, int j, int cost,
          vector<vector<vector<int>>>& dp) {
        int r = grid.size();
        int c = grid[0].size();
        if (i >= r || j >= c)
            return INT_MIN;
        int newCost = cost + (grid[i][j] > 0);

        if (newCost > k)
            return INT_MIN;

        if (i == r - 1 && j == c - 1) {
            return grid[i][j];
        }

        if(dp[i][j][cost] != -1) return dp[i][j][cost];

        int down = f(grid, k, i + 1, j, newCost, dp);
        int right = f(grid, k, i, j + 1, newCost, dp);

        int maxNext = max(down, right);
        if (maxNext == INT_MIN) {
            return dp[i][j][cost] =  INT_MIN;
        }

        return dp[i][j][cost] = maxNext + grid[i][j];
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
        int ans =  f(grid, k, 0, 0, 0, dp);
        return ans == INT_MIN ? -1 : ans;
    }
};
