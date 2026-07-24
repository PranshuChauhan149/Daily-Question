class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int INF = 1e9;

        vector<vector<int>> fire(m, vector<int>(n, INF));
        queue<pair<int, int>> q;


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fire[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;
                if (grid[nx][ny] == 2)
                    continue;
                if (fire[nx][ny] != INF)
                    continue;

                fire[nx][ny] = fire[x][y] + 1;
                q.push({nx, ny});
            }
        }

        auto can = [&](int wait) {
            if (wait >= fire[0][0])
                return false;

            vector<vector<int>> vis(m, vector<int>(n, 0));
            queue<tuple<int, int, int>> qu;

            qu.push({0, 0, wait});
            vis[0][0] = 1;

            while (!qu.empty()) {
                auto [x, y, t] = qu.front();
                qu.pop();

                if (x == m - 1 && y == n - 1)
                    return true;

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    int nt = t + 1;

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                        continue;
                    if (grid[nx][ny] == 2 || vis[nx][ny])
                        continue;

                    // Destination: arriving exactly when fire arrives is allowed
                    if (nx == m - 1 && ny == n - 1) {
                        if (nt <= fire[nx][ny]) {
                            vis[nx][ny] = 1;
                            qu.push({nx, ny, nt});
                        }
                    } else {
                        if (nt < fire[nx][ny]) {
                            vis[nx][ny] = 1;
                            qu.push({nx, ny, nt});
                        }
                    }
                }
            }

            return false;
        };

        if (!can(0))
            return -1;

        int lo = 0, hi = m * n;

        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;

            if (can(mid))
                lo = mid;
            else
                hi = mid - 1;
        }

        if (lo == m * n)
            return 1000000000;

        return lo;
    }
};