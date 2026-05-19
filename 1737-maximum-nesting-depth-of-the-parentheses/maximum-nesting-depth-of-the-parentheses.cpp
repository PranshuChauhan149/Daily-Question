class Solution {
public:
    int maxDepth(string s) {
        int b = 0;
        int ans = 0;
        for(int i =0;i<s.size();i++){
            char ch = s[i];
            if(ch == '('){
                b++;
            }
            else if(ch == ')'){
                b--;
            }
            ans = max(ans,b);
        }
        return ans;
    }
};