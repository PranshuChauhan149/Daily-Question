class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int r = grid.size();
        int c = grid[0].size();
        if (i < 0 || i >= r || j < 0 || j >= c || grid[i][j] != '1') {
            return;
        }
        grid[i][j] = '0';
        for (auto d : dir) {
            int newRow = i + d[0];
            int newCol = j + d[1];
            dfs(grid, newRow, newCol);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int count = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};