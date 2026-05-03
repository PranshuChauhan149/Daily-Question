class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!= goal.size()) return false;
        if(s==goal) return true;
        int n = goal.size();
        for(int i=1;i<n;i++){
            string str = s.substr(i,n);
            string str2 = s.substr(0,i);
            string ans = str+str2;
            if(goal == ans) return  true;
        }
        return false;
    }
};