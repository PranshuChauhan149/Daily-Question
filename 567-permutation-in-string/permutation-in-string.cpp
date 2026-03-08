class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n= s2.size();
        int n2 = s1.size();
        sort(s1.begin(),s1.end());
        for(int i=0;i<n-n2+1;i++){
            string str = s2.substr(i,n2);
            sort(str.begin(),str.end());
            if(s1==str) return true;
        }
        return false;
    }
};