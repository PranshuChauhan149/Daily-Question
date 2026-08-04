class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int s = *min_element(nums.begin(), nums.end());
        int l = *max_element(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for (auto& ele : nums) {
            mp[ele]++;
        }
        vector<int> ans;
        for (int i = s; i <= l; i++) {
            if (mp.find(i) == mp.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};