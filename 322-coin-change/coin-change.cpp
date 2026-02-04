class Solution {
public:
    vector<vector<int>> dp;
    int f(vector<int>& coins, int amount, int i) {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return 1e8;
        if (i == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            else {
                return 1e8;
            }
        }
        if (dp[i][amount] != -1)
            return dp[i][amount];
        int ans = 1e8;
        if (amount >= coins[i]) {
            ans = 1 + f(coins, amount - coins[i], i);
        }
        int a = 0 + f(coins, amount, i - 1);
        return dp[i][amount] = min(a, ans);
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        dp.resize(n + 1, vector<int>(amount + 1, 0));
        // int a = f(coins, amount, n - 1);
        // if (a == 1e8) {
        //     return -1;
        // }

        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) {
                dp[0][i] = i / coins[0];
            } else {
                dp[0][i] = 1e9;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int a = 0; a <= amount; a++) {
               
                int ans = 1e9;
                if (a >= coins[i]) {
                    ans = 1 + dp[i][a - coins[i]];
                }
                int  b = dp[i-1][a];
                 dp[i][a] = min(b, ans);
            }
        }
    
        int ans =  dp[n-1][amount];
        if(ans==1e9) return -1;
        return ans;
    }
};