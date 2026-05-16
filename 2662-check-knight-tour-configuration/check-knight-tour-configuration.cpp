class Solution {
public:
    vector<vector<int>> dir = {{-2, -1}, {-1, -2}, {-2, 1}, {-1, 2},
                               {1, -2},  {2, -1},  {2, 1},  {1, 2}};

    bool dfs(vector<vector<int>>& grid, int i, int j, int val,
             vector<vector<int>>& visited) {

        int r = grid.size();
        int c = grid[0].size();

        if (i < 0 || i >= r || j < 0 || j >= c || visited[i][j])
            return false;

        if (val == r * c - 1)
            return true;

        visited[i][j] = 1;
        for (auto d : dir) {
            int newR = d[0] + i;
            int newC = d[1] + j;
            if (newR >= 0 && newR < r && newC >= 0 && newC < c &&
                visited[newR][newC] == 0 && grid[newR][newC] == val + 1) {
                return dfs(grid, newR, newC, val + 1, visited);
            }
        }
        return false;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {

        int val = grid[0][0];
        if (val != 0)
            return false;
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> visited(r, vector<int>(c, 0));
        return dfs(grid, 0, 0, val, visited);
    }
};