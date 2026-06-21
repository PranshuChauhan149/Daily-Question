class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int cnt = 0;
        int n = nums.size();
        int ans = 0;
         mp[0] = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                cnt--;
            } else {
                cnt++;
            }
            if (cnt == 0) {
                ans = i + 1;
            }

            if (mp.find(cnt) != mp.end()) {
                ans = max(ans, i - mp[cnt]);
            }
            else{
            mp[cnt] = i;
            }
            
        }

        return ans;
    }
};