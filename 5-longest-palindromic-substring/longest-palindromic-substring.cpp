class Solution {
public:
    bool isPali(string &s) {

        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for (int i = 0; i < n; i++) {
            string str = "";
            for (int j = i; j < n; j++) {
                str += s[j];
                if (isPali(str)) {
                    if (ans.size() < str.size()) {
                        ans = str;
                    }
                }
            }
        }
        return ans;
    }
};