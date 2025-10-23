#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()>2){
            string str  = "";
            for(int i=1;i<s.size();i++){
                int a = s[i]-'0';
                int b = s[i-1] - '0';
                int ans = (a+b)%10;
                str+=to_string(ans);
                cout<<ans<<" ";
            }
            s = str;
            // cout<<s<<" ";
        }
        // cout<<s;
        return s[0]==s[1];
    }
};
int main(){

}