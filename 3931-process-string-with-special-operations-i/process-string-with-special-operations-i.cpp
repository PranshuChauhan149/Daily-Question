class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for(int i =0;i<s.size();i++){
            char ch = s[i];
            if(ch == '*'){
                if(ans.size() > 0){
                    ans.pop_back();
                }
            }
            else if(ch == '#'){
                ans += ans;
            }
            else if(ch == '%'){
                reverse(ans.begin(),ans.end());
            }else{
                ans += ch;
            }
        }
        return ans;
    }
};