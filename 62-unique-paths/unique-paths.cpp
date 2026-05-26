class Solution {
public:
    int f(int m, int n, int i, int j, vector<vector<int>>& dp) {
        if (i == m - 1 && j == n - 1)
            return 1;

        if (i < 0 || i >= m || j < 0 || j >= n)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = f(m, n, i + 1, j, dp) + f(m, n, i, j + 1, dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n, -1));
        return f(m, n, 0, 0, dp);
    }
};