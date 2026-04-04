class Solution {
public:
    string f(vector<vector<char>>& ans, int k) {
        int r = ans.size();
        int c = ans[0].size();
        int i = 0;
        int j = k;
        string str = "";
        while (i < r && j < c) {
            str += ans[i][j];
            i++;
            j++;
        }
        return str;
    }

    string decodeCiphertext(string encodedText, int rows) {
        int len = encodedText.size();
        int col = len / rows;
        vector<vector<char>> ans(rows, vector<char>(col, ' '));
        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < col; j++) {
                ans[i][j] = encodedText[k++];
            }
        }
        
        int count = 0;

        string s = "";
        for (int i = 0; i < col; i++) {
            s += f(ans, i);
        }
        string a = "";

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                count++;
            } else {
                break;
            }
        }

        a = s.substr(0, s.size() - count);

        return a;
    }
};