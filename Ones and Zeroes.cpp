class Solution {
public:
    pair<int, int> check(string s) {
        int z = 0;
        int o = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0')
                z++;
            else
                o++;
        }
        return {z, o};
    }

    int f(vector<string>& s, int m, int n, int i,
          vector<vector<vector<int>>>& dp) {
        if (i == 0) {
            auto [z, o] = check(s[0]);
            if (z <= m && o <= n)
                return 1;
            return 0;
        }
        if (dp[i][m][n] != -1)
            return dp[i][m][n];

        auto [z, o] = check(s[i]);
        int np = f(s, m, n, i - 1, dp);
        int p = 0;
        if (z <= m and o <= n) {
            p = 1 + f(s, m - z, n - o, i - 1, dp);
        }
        return dp[i][m][n] = max(np, p);
    }
    int findMaxForm(vector<string>& s, int m, int n) {
        int size = s.size();
        vector<vector<vector<int>>> dp(
            size, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        // return f(strs, m, n, strs.size() - 1, dp);
        auto [a, b] = check(s[0]);
        for (int j = a; j <= m; j++) {
            for (int k = b; k <= n; k++) {
                dp[0][j][k] = 1;
            }
        }
        for (int i = 1; i < size; i++) {
            auto [z, o] = check(s[i]);
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {

                    int np = dp[i - 1][j][k];
                    int p = 0;
                    if (z <= j and o <= k) {
                        p = 1 + dp[i - 1][j - z][k - o];
                    }
                     dp[i][j][k] = max(np, p);
                }
            }
        }
        return dp[size-1][m][n];
    }
};