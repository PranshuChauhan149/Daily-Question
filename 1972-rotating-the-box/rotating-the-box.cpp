class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>>ans(n,vector<char>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[j][m - 1 - i] = boxGrid[i][j];
            }
        }

    for(int j=0;j<m;j++){
        int s = n-1;
        int f = n-1;
        while(f>=0){
            if(ans[f][j] == '#'){
                swap(ans[s][j],ans[f][j]);
                s--;
                f--;
            }
            else if(ans[f][j] == '.'){
                f--;
            }
            else{
                f--;
                s = f;
            }


        }
    }


        return ans;
    }
};