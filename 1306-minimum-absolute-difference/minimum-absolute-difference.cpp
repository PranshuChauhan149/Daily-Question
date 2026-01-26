class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int mi = INT_MAX;
        vector<vector<int>> ans;
        for (int i = 0; i < n - 1; i++) {
            if (abs(arr[i + 1] - arr[i]) < mi) {
                mi = abs(arr[i + 1] - arr[i]);
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (abs(arr[i + 1] - arr[i]) == mi) {
                ans.push_back({arr[i], arr[i + 1]});
            }
        }
        return ans;
    }
};