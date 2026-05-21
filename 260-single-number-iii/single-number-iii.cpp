class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (auto e : nums) {
            mp[e]++;
        }
        for (auto d : mp) {
            if (d.second == 1) {
                ans.push_back(d.first);
            }
        }
        return ans;
    }
};

// 1,1,2,2,3,5