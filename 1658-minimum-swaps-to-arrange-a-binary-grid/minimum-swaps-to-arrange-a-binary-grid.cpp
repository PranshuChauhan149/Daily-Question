class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> arr;
        int n = grid.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int c = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1)
                    break;
                else {
                    c++;
                }
            }
            arr.push_back(c);
        }

        for (int i = 0; i < arr.size(); i++) {
            int req = n - i - 1;
            if (arr[i] >= req)
                continue;
            int j = i + 1;
            while (j < n && arr[j] < req)
                j++;
            if (j == n)
                return -1;
            while (j > i) {
                swap(arr[j - 1], arr[j]);
                ans++;
                j--;
            }
        }
        return ans;
    }
};