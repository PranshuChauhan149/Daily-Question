class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
        int r = board.size();
        int c = board[0].size();
        if (i < 0 || j < 0 || i >= r || j >= c || board[i][j] != word[k]) {
            return false;
        }
        if (k == word.size()-1)
            return true;
        
            char temp = board[i][j];
            board[i][j] = '-1';
        
        
        for (auto& ele : dir) {
            int a = ele[0];
            int b = ele[1];
            if(dfs(board, word, a + i, b + j, k+1) ) {

            board[i][j] =temp;
            return true;
            }
           
        }

        board[i][j] =temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<char>>& board2 = board;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(board,word,i,j,0)) return true;
            }
        }
       
        return false;
        
    }
};