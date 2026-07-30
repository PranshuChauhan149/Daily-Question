class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        for(int i =0;i<word.size();i++){
            mp[word[i]]++;
        }
        int ans = 0;
        int count = 1;
        for(auto ele : mp){
            if(count <= 8){
                ans += mp[ele.first] * 1;
            }
            else if(count > 8 && count<=16){
                ans += mp[ele.first] * 2;
            }
            else if(count > 16 && count<=24){
                ans += mp[ele.first] * 3;
            }
            else{
                ans += mp[ele.first] * 4;
            }
            count++;
        }
        return ans;
    }
};