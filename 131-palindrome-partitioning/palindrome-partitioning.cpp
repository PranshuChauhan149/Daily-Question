class Solution {
public:
    bool pl(string& s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void f(string s, vector<string>& a, vector<vector<string>>& ans) {
    if(s.size() == 0){
        ans.push_back(a);
        return;
    }

        for(int i = 0;i<s.size();i++){
            string p = s.substr(0,i+1);
            if(pl(p)){
                a.push_back(p);
                f(s.substr(i+1),a,ans);
                a.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<string> a;
        vector<vector<string>> ans;
        f(s,  a, ans);
        return ans;
    }
};