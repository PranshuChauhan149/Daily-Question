class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<string, vector<int>> mp;
        int ans = INT_MAX;

        // store indices
        for (int i = 0; i < nums.size(); i++) {
            mp[to_string(nums[i])].push_back(i);
        }

        for (int i = 0; i < nums.size(); i++) {
            string str = to_string(nums[i]);
            reverse(str.begin(), str.end());

            int val = stoi(str);
            string s = to_string(val);

            if (mp.find(s) != mp.end()) {
                auto &vec = mp[s];

                // 🔥 find first index > i
                auto it = upper_bound(vec.begin(), vec.end(), i);

                if (it != vec.end()) {
                    ans = min(ans, *it - i);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};