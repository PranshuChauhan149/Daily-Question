class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> a(3, -1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            a[s[i] - 'a'] = i;
            if (a[0] != -1 && a[1] != -1 && a[2] != -1) {
                ans += 1 + min({a[0], a[1], a[2]});
            }
        }
        return ans;
    }
};