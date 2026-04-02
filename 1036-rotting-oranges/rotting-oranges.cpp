class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> qu;
        int r = grid.size();
        int c = grid[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    qu.push({{i, j}, 0});
                }
            }
        }

        int ans = 0;

        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        while (!qu.empty()) {
            auto ele = qu.front();
            qu.pop();
            int rr = ele.first.first;
            int cc = ele.first.second;
            int time = ele.second;
            ans = max(ans, time);

            for (auto d : dir) {
                int newRow = rr + d[0];
                int newCol = cc + d[1];

                if (newRow >= 0 && newCol >= 0 && newRow < r && newCol < c &&
                    grid[newRow][newCol] == 1) {
                    grid[newRow][newCol] = 2;
                    qu.push({{newRow, newCol}, time + 1});
                }
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1) return -1;
            }
        }

        return ans;
    }
};