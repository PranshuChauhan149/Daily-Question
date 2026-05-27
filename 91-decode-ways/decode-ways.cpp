class Solution {
public:
    int f(string s, int i,vector<int>&dp) {
        if (i == s.size())
            return 1;
        if (s[i] == '0')
            return 0;
if(dp[i]!=-1) return dp[i];
        int p = f(s, i + 1,dp);
        int p2 = 0;

        if (i + 1 < s.size()) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

            if (num >= 10 && num <= 26) {
                p2 = f(s, i + 2,dp);
            }
           
        }
        return dp[i] =  p + p2;
    }

    int numDecodings(string s) { 
        
        vector<int>dp(s.size()+1,-1);
        return f(s, 0,dp);
         }
};