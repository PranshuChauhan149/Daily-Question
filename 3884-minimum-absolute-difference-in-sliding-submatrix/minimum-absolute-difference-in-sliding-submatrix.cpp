class Solution {
public:
   int f(vector<int>& arr) {
    sort(arr.begin(), arr.end());

  
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    int mi = INT_MAX;

    for (int i = 0; i < arr.size() - 1; i++) {
        mi = min(mi, abs(arr[i + 1] - arr[i]));
    }

    return (mi == INT_MAX ? 0 : mi);
}

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int kk) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i <= n - kk; i++) {
            vector<int> a;
            for (int j = 0; j <= m - kk; j++) {

                vector<int> arr;
                for (int k = i; k < i + kk; k++) {
                    for (int l = j; l < j+kk; l++) {
                        arr.push_back(grid[k][l]);
                    }
                }

                a.push_back(f(arr));
            }
            ans.push_back(a);
        }
        return ans;
    }
};