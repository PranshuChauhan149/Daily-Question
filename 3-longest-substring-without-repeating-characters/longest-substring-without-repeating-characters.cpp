class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        unordered_map<char, int> mp;
        while (j < n) {
            char ch = s[j];
            if (mp.find(ch) != mp.end()) {
                if (mp[ch] >= i) {
                    i = mp[ch] + 1;
                }
            }

            ans = max(ans, j - i + 1);

            mp[ch] = j;
            j++;
        }
        return ans;
    }
};