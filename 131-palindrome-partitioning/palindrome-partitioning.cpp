class Solution {
public:

    bool check(string str){
        int i = 0;
        int j = str.size()-1;
        while(i<=j){
            if(str[i]!=str[j]) return false;
             i++;
            j--;
        }
        return true;
    }

    void f(string s, vector<string>& a, vector<vector<string>>& ans) {
        int n = s.size();

        if(s.size() == 0){
            ans.push_back(a);
        }

        for (int i = 0; i < n; i++) {
            string str = s.substr(0, i + 1);
            if (check(str)) {
                a.push_back(str);
                f(s.substr(i + 1), a, ans);
                a.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> a;
        vector<vector<string>> ans;
        f(s, a, ans);
        return ans;
    }
};