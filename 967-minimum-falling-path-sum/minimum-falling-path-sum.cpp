class Solution {
public:
    int f(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {
        int r = matrix.size();
        int c = matrix[0].size();
        if (i >= r || j >= c || j < 0)
            return 1e9;
        if (i == r - 1)
            return matrix[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int d = matrix[i][j] + f(matrix, i + 1, j, dp);
        int a = matrix[i][j] + f(matrix, i + 1, j + 1, dp);
        int b = matrix[i][j] + f(matrix, i + 1, j - 1, dp);

        return dp[i][j] = min({d, a, b});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int ans = INT_MAX;
        int r = matrix.size();
        int c = matrix[0].size();

        vector<vector<int>> dp;
        dp.assign(r + 1, vector<int>(c + 1, 1e9));
        //  for(int i=0;i<matrix.size();i++){
        //     ans =min(ans,f(matrix,0,i,dp));
        //  }

        for (int i = 0; i < r; i++) {
            dp[0][i] = matrix[0][i];
        }

        for (int i = 1; i < r ; i++) {
            for (int j = 0; j < c; j++) {

                int d= dp[i -1][j];
                int a = (j > 0) ? dp[i - 1][j - 1] : 1e9;
                int b = (j < c - 1) ? dp[i - 1][j + 1] : 1e9;

                dp[i][j] = matrix[i][j] + min({d, a, b});
            }
        }

       int ans = *min_element(dp[r-1].begin(), dp[r-1].end());
return ans;


    }
};