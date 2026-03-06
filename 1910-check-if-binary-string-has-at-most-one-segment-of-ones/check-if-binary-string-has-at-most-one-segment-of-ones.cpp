class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        bool f= false;
        for(int i=0;i<n;i++){
            if(f && s[i]=='1') return false;
            if(s[i]=='0') {
                f = true;
            }
        }
        return true;
    }
};