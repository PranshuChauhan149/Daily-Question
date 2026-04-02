class Solution {
public:
    int f(vector<vector<int>>& coins, int i, int j, int count,vector<vector<vector<int>>>&dp) {

        int r = coins.size();
        int c = coins[0].size();

        if (i >= r || j >= c)
            return -1e9;

        if (i == r - 1 && j == c - 1) {
            if (coins[i][j] < 0 && count > 0) {
                return 0;
            }
            return coins[i][j];
        }

        if(dp[i][j][count]!=INT_MIN) return dp[i][j][count];

        int ans = coins[i][j] +
                  max(f(coins, i + 1, j, count,dp), f(coins, i, j + 1, count,dp));
        int sk = -1e9;
        if (coins[i][j] < 0 && count > 0) {
            int skip = f(coins, i + 1, j, count - 1,dp);
            int skip2 = f(coins, i, j + 1, count - 1,dp);
            sk = max(skip, skip2);
        }

        return dp[i][j][count] =  max(sk, ans);
    }

    int maximumAmount(vector<vector<int>>& coins) { 
        int r = coins.size();
        int c = coins[0].size();
        vector<vector<vector<int>>>dp(r+1,vector<vector<int>>(c+1,vector<int>(2+1,INT_MIN)));
        return f(coins, 0, 0, 2,dp); 
        }
};