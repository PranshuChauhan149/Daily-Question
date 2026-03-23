class Solution {
public:
    bool f(string s, int i, int count, vector<vector<int>>& dp) {
        if (count < 0)
            return false;
        if (i == s.size()) {
            if (count == 0)
                return true;
            else
                return false;
        }
        if (dp[i][count] != -1)
            return dp[i][count];

        if (s[i] == '(') {
            return dp[i][count] = f(s, i + 1, count + 1, dp);
        }
        if (s[i] == ')') {
            return dp[i][count] = f(s, i + 1, count - 1, dp);
        }

        return dp[i][count] = f(s, i + 1, count + 1, dp) ||
                              f(s, i + 1, count - 1, dp) ||
                              f(s, i + 1, count, dp);
    }

    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, -1));
        return f(s, 0, 0, dp);
    }
};