class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int ans = 0;
        int a = 0;
        for (int i = 0; i < n; i++) {

            ans += gain[i];
            a = max(ans, a);
        }
        return a;
    }
};