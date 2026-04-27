class Solution {
public:
    unordered_map<int, vector<vector<int>>> directions = {
        {1, {{0, -1}, {0, 1}}},  {2, {{-1, 0}, {1, 0}}},
        {3, {{0, -1}, {1, 0}}},  {4, {{0, 1}, {1, 0}}},
        {5, {{0, -1}, {-1, 0}}}, {6, {{-1, 0}, {0, 1}}}};
    bool dfs(vector<vector<int>>& grid, int i, int j,
             vector<vector<int>>& visited) {
        int n = grid.size();
        int m = grid[0].size();

        if (i == n - 1 && j == m - 1)
            return true;

        visited[i][j] = 1;

        for (auto d : directions[grid[i][j]]) {
            int new_i = i + d[0];
            int new_j = j + d[1];

            if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= m ||
                visited[new_i][new_j])
                continue;

            bool valid = false;

            for (auto dr : directions[grid[new_i][new_j]]) {
                if (new_i + dr[0] == i && new_j + dr[1] == j) {
                    valid = true;
                    break;
                }
            }

            if (valid) {
                if (dfs(grid, new_i, new_j, visited))
                    return true;
            }
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        return dfs(grid, 0, 0, visited);
    }
};