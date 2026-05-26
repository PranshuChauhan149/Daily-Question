class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int idx) {
        int n = board.size();
        int m = board[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[idx]) {
            return false;
        }
        if (idx == word.size() - 1)
            return true;

        char temp = board[i][j];
        board[i][j] = '#';

        for (auto& d : dir) {

            int newR = i + d[0];
            int newC = j + d[1];

            if (dfs(board, newR, newC, word, idx + 1)) {

                board[i][j] = temp;
                return true;
            }
        }

        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {

                    if (dfs(board, i, j, word, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};