class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    bool dfs(vector<vector<char>>& grid, int i, int j,
             vector<vector<int>>& visited, char ch, pair<int, int> prt) {
        int n = grid.size();
        int m = grid[0].size();
        visited[i][j] = 1;
        
        for (auto d : dir) {
            int newR = i + d[0];
            int newC = j + d[1];
        if (newR < 0 || newR >= n || newC < 0 || newC >= m ||
                grid[newR][newC] != ch)
                continue;
            if (visited[newR][newC]) {
                if (newR != prt.first || newC != prt.second)
                    return true;
            } else {
                if (dfs(grid, newR, newC, visited, ch, {i, j}) == true)
                    return true;
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid, i, j, visited, grid[i][j], {i, j}))
                        return true;
                }
            }
        }
        return false;
    }
};