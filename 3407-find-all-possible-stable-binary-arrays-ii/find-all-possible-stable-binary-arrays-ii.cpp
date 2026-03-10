class Solution {
public:
    int MOD = 1e9 + 7;

    int numberOfStableArrays(int zero, int one, int limit) {

        vector<vector<vector<int>>> dpMemo(
            zero + 1, vector<vector<int>>(one + 1, vector<int>(2, -1)));

        function<int(int,int,int)> solve = [&](int z, int o, int last) -> int {

            if (z == 0) {
                return (last == 0 || o > limit) ? 0 : 1;
            }

            if (o == 0) {
                return (last == 1 || z > limit) ? 0 : 1;
            }

            if (dpMemo[z][o][last] != -1)
                return dpMemo[z][o][last];

            int ans = 0;

            if (last == 0) {

                ans = (solve(z-1, o, 0) + solve(z-1, o, 1)) % MOD;

                if (z > limit)
                    ans = (ans - solve(z-limit-1, o, 1) + MOD) % MOD;

            } else {

                ans = (solve(z, o-1, 0) + solve(z, o-1, 1)) % MOD;

                if (o > limit)
                    ans = (ans - solve(z, o-limit-1, 0) + MOD) % MOD;
            }

            return dpMemo[z][o][last] = ans;
        };

        return (solve(zero, one, 0) + solve(zero, one, 1)) % MOD;
    }
};