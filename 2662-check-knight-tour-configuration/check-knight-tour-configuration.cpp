class Solution {
public:
    vector<vector<int>> dir = {
        {-2, -1}, {-1, -2}, {-2, 1}, {-1, 2},
        {1, -2},  {2, -1},  {2, 1},  {1, 2}
    };

    bool f(vector<vector<int>>& grid, int val, int r, int c,
           vector<vector<int>>& visited) {

        int row = grid.size();
        int col = grid[0].size();

        
        if (r < 0 || r >= row || c < 0 || c >= col)
            return false;

        if (visited[r][c])
            return false;

       
        if (val == row * col - 1)
            return true;

        visited[r][c] = 1;

        
        for (auto d : dir) {
            int nRow = r + d[0];
            int nCol = c + d[1];

            if (nRow >= 0 && nRow < row && nCol >= 0 && nCol < col) {
                if (grid[nRow][nCol] == val + 1) {
                    return f(grid, val + 1, nRow, nCol, visited);
                }
            }
        }

        return false;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

     
        if (grid[0][0] != 0) return false;

        vector<vector<int>> visited(n, vector<int>(n, 0));
        return f(grid, 0, 0, 0, visited);
    }
};
