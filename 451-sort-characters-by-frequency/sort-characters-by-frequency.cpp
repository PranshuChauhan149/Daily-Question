class Solution {
public:


    static bool cmp(pair<char,int>&a,pair<char,int>&b){
        return a.second > b.second;
    }

    string frequencySort(string s) {
        vector<pair<char,int>>mp(255);
        for(int i =0;i<s.size();i++){
            char ch = s[i];
            mp[ch].first = ch;
            mp[ch].second++;
        }
        string ans = "";
        sort(mp.begin(),mp.end(),cmp);
        for(int i = 0;i<mp.size();i++){
            int d = mp[i].second;
            char ch = mp[i].first;
            string str = string(d,ch);
     
            ans+=str;
        }
        return ans;
    }
};