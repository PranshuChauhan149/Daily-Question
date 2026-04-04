class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();

        vector<vector<int>> ans(r, vector<int>(c, 0));
        vector<vector<int>> visited(r, vector<int>(c, 0));
        queue<pair<pair<int, int>, int>> qu;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 0) {
                    qu.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        while (!qu.empty()) {
            auto ele = qu.front();
            qu.pop();
            int row = ele.first.first;
            int col = ele.first.second;
            int val = ele.second;

            ans[row][col] = val;

            for (auto e : dir) {
                int newRow = row + e[0];
                int newCol = col + e[1];
                if (newRow >= 0 && newRow < r && newCol >= 0 && newCol < c &&
                    visited[newRow][newCol] == 0) {
                    qu.push({{newRow, newCol}, val + 1});
                    visited[newRow][newCol] = 1;
                }
            }
        }
        return ans;
    }
};