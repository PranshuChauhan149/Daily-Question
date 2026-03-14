class Solution {
public:
    void f(int n, string& s,vector<string>&ans) {
        if (s.size() == n) {
            ans.push_back(s);
            return;
        }
        for (int i = 0; i < 3; i++) {
            char ch = 'a' + i;

            if (s.empty() || s.back() != ch) {
                s.push_back(ch);
                f(n, s,ans);
                s.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string>ans;
        string s = "";
        f(n, s,ans);
        if(k > ans.size()) return "";

        return ans[k-1];
    }
};