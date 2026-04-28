class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int r = grid.size();
        int c = grid[0].size();
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {

                ans.push_back(grid[i][j]);
            }
        }
        for (int num : ans) {
            if ((num - ans[0]) % x != 0) {
                return -1;
            }
        }
        sort(ans.begin(), ans.end());
        int n = ans.size();
        if (n == 1)
            return 0;
        int mid = n / 2 ;
        int a = ans[mid];
        int count = 0;
        for (int i = 0; i < n; i++) {

            if (ans[i] == a)
                continue;
            else {

                count += abs(ans[i] - a) / x;
            }
        }
        return count;
    }
};