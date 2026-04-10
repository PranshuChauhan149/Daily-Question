class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = INT_MAX;
        while (j < n) {
            int ele = nums[j];
            if (mp[ele].size() == 2) {
                vector<int> a = mp[ele];
                int x = abs(abs(a[0] - a[1]) + abs(a[1] - j) + abs(j - a[0]));
                ans = min(ans, x);
                mp[ele].erase(mp[ele].begin());
            }
            mp[ele].push_back(j);
            j++;
        }
        return ans==INT_MAX ? -1 : ans;
    }
};