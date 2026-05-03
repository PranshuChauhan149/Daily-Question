class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0)
            return false;
        if (k == 1)
            return true;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for (auto d : nums) {
            mp[d]++;
        }

        for (int i = 0; i < n; i++) {

            if (mp[nums[i]] == 0) {
                continue;
            }

            int d = nums[i];

            for (int j = 0; j < k; j++) {
                int curr = d + j;
                if (mp[curr] == 0)
                    return false;

                mp[curr]--;
                if (mp[curr] == 0) {
                    mp.erase(curr);
                }
            }
        }
        return true;
    }
};
