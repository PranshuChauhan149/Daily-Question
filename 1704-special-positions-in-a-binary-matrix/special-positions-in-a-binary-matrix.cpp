class Solution {
public:

    bool check(vector<vector<int>>&mat,int i1,int j1){
        int r = mat.size();
        int c = mat[0].size();
        for(int j=0;j<c;j++){
            if(j!=j1 && mat[i1][j]==1) return false;
        }
        for(int i=0;i<r;i++){
            if(i!=i1 && mat[i][j1]==1) return false;
        }
        return true;
    }

    int numSpecial(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        int count = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==1){
                    if(check(mat,i,j)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};