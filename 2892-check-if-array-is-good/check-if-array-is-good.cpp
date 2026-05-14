class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ele = nums.size() - 1;

        for (auto d : nums) {
            mp[d]++;
            if (d > ele)
                return false;
        }
        bool flag = false;
        for (auto d : mp) {
            if (d.second == 2) {
                flag = true;
            }
        
            if (d.second >= 2 && d.first != ele) {
                return false;
            }
        }
        return flag;
    }
};