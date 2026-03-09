class Solution {
public:
    int MOD = 1e9 + 7;

    int dp[201][201][2];

    int f(int zero, int one, bool curr, int limit) {
        if (zero == 0 && one == 0)
            return 1;
        if(dp[zero][one][curr]!=-1) return dp[zero][one][curr];
        long long ans = 0;
        if (curr) {
            for (int i = 1; i <= min(limit, zero); i++) {
                ans = (ans + f(zero - i, one, false, limit)) % MOD;
                
            }
        } else {
            for (int i = 1; i <= min(limit, one); i++) {
                ans = (ans + f(zero, one - i, true, limit)) % MOD;
                ;
            }
        }
        return   dp[zero][one][curr] =  ans;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        ans = (ans + f(zero, one, true, limit)) % MOD;
        ans = (ans + f(zero, one, false, limit)) % MOD;
        return ans;
    }
};