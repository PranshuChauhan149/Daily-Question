class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (ch >= 'a' && ch <= 'z') {
                mp1[ch] = i;
            } else {
                if (mp2.find(ch) == mp2.end()) {
                    mp2[ch] = i;
                }
            }
        }
        int ans = 0;
        for (auto& d : mp2) {
            char ch = d.first + 32;
            cout<<ch;
            if (mp1.find(ch) != mp1.end()) {
                if (mp1[ch] < mp2[d.first]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};