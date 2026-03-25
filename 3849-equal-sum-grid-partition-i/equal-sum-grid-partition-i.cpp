class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<long long> pref;
        vector<long long> suef(n);
        vector<long long> pref1(m);
        vector<long long> suef1(m);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum = sum + grid[i][j];
            }
            pref.push_back(sum);
        }
        long long s = 0;
        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                s += grid[i][j];
            }
            suef[i] =s ;
        }
        int r = pref.size();
        int c = suef.size();

    long long aa = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                aa+=grid[j][i];
            }
            pref1[i] = aa;
        }


        long long bb =0;
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<n;j++){
                bb+=grid[j][i];
            }
            suef1[i]=bb;
        }




       

        for(int i=1;i<n;i++){
            if(pref[i-1] == suef[i]) return true;
        }
        for(int i=1;i<m;i++){
            if(pref1[i-1] == suef1[i]) return true;
        }





        return false;
    }
};
