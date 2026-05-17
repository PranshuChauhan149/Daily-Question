class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto s : strs) {
            string str = s;
          sort(s.begin(), s.end());
            mp[s].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto d : mp) {
            vector<string> a;
            for (auto e : d.second) {
        a.push_back(e);
    }
            ans.push_back(a);
        }
        return ans;
    }
};