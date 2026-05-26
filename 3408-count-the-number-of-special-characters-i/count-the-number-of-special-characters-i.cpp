class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> arr(255, 0);
        int count = 0;
       set<char> st(word.begin(), word.end());
        for (auto ch : st) {
            if (ch >= 'a' && ch <= 'z') {
                arr[ch - 'a']++;
                if (arr[ch - 'a'] > 1) {
                    count++;
                }
            }
            else{
                arr[ch - 'A']++;
                if (arr[ch - 'A'] > 1) {
                    count++;
                }
            }
        }
        return count;
    }
};