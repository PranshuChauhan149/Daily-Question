class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>ans;
        for(int i=x;i<x+k;i++){
            vector<int>a;
            for(int j=y;j<y+k;j++){
                a.push_back(grid[i][j]);
            }
            ans.push_back(a);
        }
        int i = 0;
        int j = ans.size()-1;
        while(i<j){
            swap(ans[i],ans[j]);
            i++;
            j--;
        }
        for(int kk=x;kk<x+k;kk++){
            for(int l=y;l<y+k;l++){
                grid[kk][l] = ans[kk-x][l-y];
            }
        }
        return grid;
    }
};