class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        if(k < grid[0][0]) return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            int s =0;
            for(int j=0;j<m;j++){
                s += grid[i][j];
                ans[i][j] = s;
            }
        }
        for(int i=1;i<n;i++){
    
            for(int j=0;j<m;j++){
                
                ans[i][j] += ans[i-1][j];
            }
        }
    int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ans[i][j] <= k) count++;
            }
            cout<<endl;
        }
        return count;
    }
};