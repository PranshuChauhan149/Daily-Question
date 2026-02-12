class Solution {
public:
    bool check(unordered_map<char,int>&mp) {
       
        int feq = -1;
        for(auto dd : mp){
            if(feq==-1){
                feq=dd.second;
            }
            else if(feq!=dd.second){
                return false;
            }
        }
        return true;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char,int>mp;
            for (int j = i; j < n; j++) {
                mp[s[j]]++;
                if (check(mp) ){
                    count = max(count,j-i+1);
                }
            }
        }
        return count;
    }
};