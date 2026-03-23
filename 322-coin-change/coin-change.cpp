class Solution {
public:
    int f(vector<int>& coins, int i, int amount, vector<vector<int>>& dp) {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return 1e9;
        if (i == coins.size() - 1) {
            if (amount % coins[i] == 0) {
                return amount / coins[i];
            }
            return 1e9;
        }

        if (dp[i][amount] != -1)
            return dp[i][amount];
        int p = 1e9;

        if (amount >= coins[i]) {
            p = 1 + f(coins, i, amount - coins[i], dp);
        }
        int r = f(coins, i + 1, amount, dp);
        return dp[i][amount] = min(p, r);
    }

    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>( amount + 1, -1));
        int ans = f(coins, 0, amount, dp);

        return ans == 1e9 ? -1 : ans;
    }
};