class Solution {
public:
    typedef long long ll;
    const int MOD = 1e9 + 7;
    pair<ll, ll> f(vector<vector<int>>& grid, int i, int j,
                   vector<vector<pair<ll, ll>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        if (i == n - 1 && j == m - 1) {
            return {grid[i][j], grid[i][j]};
        }

        auto d = dp[i][j];
        if (d.first != LLONG_MIN && d.second != LLONG_MAX)
            return d;

        ll minval = LLONG_MAX;
        ll maxval = LLONG_MIN;

        if (i + 1 < n) {
            auto [a, b] = f(grid, i + 1, j, dp);
            minval = min({minval, grid[i][j] * a, grid[i][j] * b});
            maxval = max({maxval, grid[i][j] * a, grid[i][j] * b});
        }

        if (j + 1 < m) {
            auto [a, b] = f(grid, i, j + 1, dp);
            minval = min({minval, grid[i][j] * a, grid[i][j] * b});
            maxval = max({maxval, grid[i][j] * a, grid[i][j] * b});
        }
        return dp[i][j] = {minval, maxval};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<pair<ll, ll>>> dp(
            n + 1, vector<pair<ll, ll>>(m + 1, {LLONG_MIN, LLONG_MAX}));
        auto a = f(grid, 0, 0, dp);
        ll ans = max(a.first, a.second);
        if (ans < 0)
            return -1;
        return ans % MOD;
    }
};