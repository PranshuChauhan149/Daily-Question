class Solution {
public:
   vector<string> arr = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void f(string str, string& s, int idx, vector<string>& ans) {
        int n = str.size();
        if (idx == n) {
            if(!s.empty()) ans.push_back(s);
            return;
        }

        int d = str[idx] - '0';
        string g = arr[d];

        for (int i = 0; i < g.size(); i++) {
            s += g[i];
            f(str, s, idx + 1, ans);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string s = "";
        f(digits, s, 0, ans);
        return ans;
    }
};