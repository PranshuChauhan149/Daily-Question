class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> preff(n * m, 0);
        vector<int> sueff(n * m, 0);
      
        int k = 0;
        long long p = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                p = (p * grid[i][j]) % 12345;
                preff[k++] = p;
            }
        }
        k = m * n - 1;
        long long p2 = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                p2 = (p2 * grid[i][j]) % 12345;
                sueff[k--] = p2 ;
            }
        }


    for(int i=0;i<m*n;i++){
        cout<<preff[i]<<" ";
    }
        cout<<endl;
     for(int i=0;i<m*n;i++){
        cout<<sueff[i]<<" ";
    }

    vector<int>a;
    vector<vector<int>>ans;
        for(int i=0;i<n*m;i++){
        long long aa = 1;
            if(i > 0){
                aa*=preff[i-1];
            }
            if(i<n*m-1){
                aa*=sueff[i+1];
            }
            a.push_back(aa % 12345);
            if(a.size()==m){
                ans.push_back(a);
                a.clear();
            }
        }

        
        

        return ans;
    }
};