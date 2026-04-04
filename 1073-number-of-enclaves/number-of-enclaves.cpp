class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
             int r = board.size();
        int c = board[0].size();

        queue<pair<int, int>> qu;
        for (int i = 0; i < c; i++) {
            if (board[0][i] == 1) {
                board[0][i] = -1;
                qu.push({0, i});
            }
            if (board[r - 1][i] == 1) {
                board[r - 1][i] = -1;
                qu.push({r - 1, i});
            }
        }
        for (int i = 1; i < r - 1; i++) {
            if (board[i][0] == 1) {
                board[i][0] =-1;
                qu.push({i, 0});
            }
            if (board[i][c - 1] == 1) {
                board[i][c - 1] = -1;
                qu.push({i, c - 1});
            }
        }
        cout << qu.size();
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while (!qu.empty()) {
            auto ele = qu.front();
            qu.pop();
            int row = ele.first;
            int col = ele.second;

            board[row][col] = -1;

            for (auto e : dir) {
                int newRow = row + e[0];
                int newCol = col + e[1];

                if (newRow >= 0 && newRow < r && newCol >= 0 && newCol < c &&
                    board[newRow][newCol] == 1) {
                        board[newRow][newCol] =-1;
                    qu.push({newRow, newCol});
                }
            }
        }
        int count=0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 1) {
                    count++;
                } 
            }
        }
        return count;
    }
};