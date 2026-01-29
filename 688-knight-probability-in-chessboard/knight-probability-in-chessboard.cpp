class Solution {
public:

    
    double dp[28][28][105];
    vector<vector<int>> dir = {{-2, -1}, {-1, -2}, {-2, 1}, {-1, 2},
                               {1, -2},  {2, -1},  {2, 1},  {1, 2}};

    double f(int n, int k, int row, int col) {
        if (isvalid(row, col, n) == false)
            return 0;
        if (k == 0)
            return 1;
        if(dp[row][col][k]!=-1) return dp[row][col][k];
        double prob = 0;
        for (auto d : dir) {
            prob += f(n, k - 1, row + d[0], col + d[1]) / 8.0;
        }
        return dp[row][col][k] =  prob;
    }

    bool isvalid(int r, int c, int n) {
        if (r < 0 || r >= n || c < 0 || c >= n)
            return false;
        return true;
    }

    double knightProbability(int n, int k, int row, int column) {
        for (int i = 0; i < 28; i++)
            for (int j = 0; j < 28; j++)
                for (int m = 0; m < 105; m++)
                    dp[i][j][m] = -1;

        return f(n, k, row, column);
    }
};