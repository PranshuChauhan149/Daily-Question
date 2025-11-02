class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    void dfs(vector<vector<int>>& ans, int i, int j,vector<int>&d) {
        int r = ans.size();
        int c = ans[0].size();
        if (i < 0 || j < 0 || i >= r || j >= c || ans[i][j] == 0 ||
            ans[i][j] == -2) {
            return;
        }
        if (ans[i][j] == 1)
            ans[i][j] = -1;

        dfs(ans, i + d[0], j + d[1], d);
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> ans(m, vector<int>(n, 1));

        for (int i = 0; i < walls.size(); i++) {
            int a = walls[i][0];
            int b = walls[i][1];
            ans[a][b] = 0;
        }

        for (int i = 0; i < guards.size(); i++) {
            int a = guards[i][0];
            int b = guards[i][1];
            ans[a][b] = -2;
        }
        for (auto g : guards) {
            int x = g[0];
            int y = g[1];
            for (auto d : dir) {
                dfs(ans, x + d[0], y + d[1], d);
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              if(ans[i][j]==1) count++;
            }
        }
        return count;
    }
};