class Solution {
public:
    bool f(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i < j) {
                    swap(mat[i][j], mat[j][i]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != target[i][j]) {
                    return false;
                    break;
                }
            }
        }
        return true;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < 4; i++) {
            if (f(mat, target))
                return true;
        }
        return false;
    }
};