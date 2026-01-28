class Solution {
public:

    vector<vector<string>>ans;
    vector<vector<char>>grid;

   bool check(int r, int c) {
        int n = grid.size();
        for (int i = r; i >= 0; i--) {
            if (grid[i][c] == 'Q') {
                return false;
            }
        }
        for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
            if (grid[i][j] == 'Q')
                return false;
        }

        for (int i = r, j = c; i >= 0 && j < n; i--, j++) {
            if (grid[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void f(int n,int i){

      if(i == n){
    vector<string> a;
    for(int k = 0; k < n; k++){
        string s = "";   
        for(int l = 0; l < n; l++){
            s += grid[k][l];
        }
        a.push_back(s);
    }
    ans.push_back(a);
    return;
}

        for(int j=0;j<n;j++){
            if(check(i,j)){
                grid[i][j] = 'Q';
                f(n,i+1);
                grid[i][j] = '.';
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        grid.clear();
        grid.resize(n,vector<char>(n,'.'));
        f( n,0);
        return ans;

    }
};