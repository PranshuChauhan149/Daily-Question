class Solution {
public:
vector<vector<int>>dp;
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
    if(dp[i][amount]!=-1) return dp[i][amount];
    int ans = 1e8;
    if (amount >= coins[i]) {
        ans = 1 + f(coins, amount - coins[i], i);
    }
    int a = 0 + f(coins, amount, i - 1);
    return dp[i][amount] =  min(a, ans);
}

    int coinChange(vector<int>& coins, int amount) {

    int n = coins.size();
    dp.resize(n+1,vector<int>(amount+1,-1));
    int a = f(coins, amount, n - 1);
    if (a == 1e8) {
        return -1;
    }
    return a;
}
}
;