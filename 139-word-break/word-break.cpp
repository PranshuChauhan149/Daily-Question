class Solution {
public:
    bool f(string s, int idx, unordered_map<string, int>& mp,vector<int>&dp) {
        if (idx == s.size())
            return true;
        if(dp[idx]!=-1) return dp[idx];
        string temp = "";
        for (int i = idx; i < s.size(); i++) {
            temp += s[i];
            if (mp.find(temp) != mp.end()) {
                if(f(s, i + 1, mp,dp)){
                    return dp[idx] = true;
                }
            }
        }

        return dp[idx] =  false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> mp;
        for (int i = 0; i < wordDict.size(); i++) {
            mp[wordDict[i]]++;
        }
        vector<int>dp(302,-1);
    
        return f(s, 0, mp,dp);
    }
};