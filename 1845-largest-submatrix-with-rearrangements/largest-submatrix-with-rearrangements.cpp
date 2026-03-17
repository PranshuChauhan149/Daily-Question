class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1 && i > 0) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }

            vector<int> h = matrix[i];
            sort(h.begin(), h.end(), greater<int>());

            for (int k = 0; k < n; k++) {
                int base = k + 1;
                int hei = h[k];

                maxArea = max(maxArea, base * hei);
            }
        }
        return maxArea;
    }
};