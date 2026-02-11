class Solution {
public:
    bool check(string str) {
        int i = 0;
        int j = str.size() - 1;
        while (i <= j) {
            if (str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    void f(string s, int idx, vector<vector<string>> &ans, vector<string>& a) {
        if (idx == s.size()) {
            ans.push_back(a);
        return;
        }
        for (int i = idx; i < s.size(); i++) {
            if (check(s.substr(idx, i - idx + 1))) {
                a.push_back(s.substr(idx, i - idx + 1));
                f(s, i + 1, ans, a);
                a.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        string str = "";
        vector<vector<string>> ans;
        vector<string> a;
        f(s, 0, ans, a);
        return ans;
    }
};