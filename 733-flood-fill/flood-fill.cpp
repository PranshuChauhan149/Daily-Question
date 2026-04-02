class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    void dfs(vector<vector<int>>& image, int i, int j, int newColor,
             int color) {
        int r = image.size();
        int c = image[0].size();
        if (i < 0 || j < 0  || i >= r || j >= c || image[i][j] != color)
            return;
        image[i][j] = newColor;
        for (auto d : dir) {
            int newRow = i + d[0];
            int newCol = j + d[1];

            dfs(image, newRow, newCol, newColor, color);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        if (image[sr][sc] == color)
            return image;
        int c = image[sr][sc];
        dfs(image, sr, sc, color, c);
        return image;
    }
};