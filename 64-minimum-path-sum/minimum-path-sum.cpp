class Solution {
public:

    int f(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp){
        int r = grid.size();
        int c = grid[0].size();
        if(i==r-1 && j==c-1) return grid[i][j];
        if(i>=r || j>=c) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];

        int up = grid[i][j] + f(grid,i+1,j,dp);
        int down = grid[i][j] + f(grid,i,j+1,dp);
        return dp[i][j] =  min(up,down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>>dp(r+1,vector<int>(c+1,-1));
        return f(grid,0,0,dp);
    }
};