class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        string str1Even = "";
        string str1odd = "";
        string str2Even = "";
        string str2odd = "";
        for(int i=0;i<n;i++){
            if(i%2==0){
            str1Even += s1[i];
            str2Even += s2[i];
            }
            else{
                str1odd += s1[i];
                str2odd += s2[i];
            }
        }
        sort(str1Even.begin(),str1Even.end());
        sort(str1odd.begin(),str1odd.end());
        sort(str2Even.begin(),str2Even.end());
        sort(str2odd.begin(),str2odd.end());
        return str1Even == str2Even && str1odd == str2odd;
    }
};