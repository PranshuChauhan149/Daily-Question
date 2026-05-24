class Solution {
public:
    int passwordStrength(string password) {
        unordered_map<char, int> mp;
        for (auto& p : password) {
            mp[p]++;
        }
        int s = 0;
        for (auto& d : mp) {
            char ch = d.first;
            if (ch == '!' || ch == '@' || ch == '#' || ch == '$') {
                s += 5;
            } else if (ch >= 'a' && ch <= 'z') {
                s += 1;
            } else if (ch >= 'A' && ch <= 'Z') {
                s += 2;
            } else if (ch >= '0' && ch <= '9') {
                s += 3;
            }
        }
        return s;
    }
};