class Solution {
public:
    bool f(vector<int>& arr, int idx, vector<bool>& visited, vector<int>& dp) {
        if (idx < 0 || idx >= arr.size() || visited[idx])
            return false;
        if (arr[idx] == 0)
            return true;
        bool a = false;
        bool b = false;

        visited[idx] = true;

        if (dp[idx] != -1)
            return dp[idx];

        if (idx + arr[idx] < arr.size()) {

            a = f(arr, idx + arr[idx], visited, dp);
        }
        if (idx - arr[idx] >= 0) {

            b = f(arr, idx - arr[idx], visited, dp);
        }

        return dp[idx] = a || b;
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        vector<bool> visited(n + 1, 0);

        return f(arr, start, visited, dp);
    }
};