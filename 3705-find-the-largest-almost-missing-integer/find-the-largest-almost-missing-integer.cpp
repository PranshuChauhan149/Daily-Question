// class Solution {
// public:
//     int largestInteger(vector<int>& nums, int k) {
    
//         int n = nums.size();
//         if(k==n){
//             return *max_element(nums.begin(),nums.end());
//         }
//         unordered_map<int, int> mp;
//         for (int i = 0; i < n; i++) {
//             mp[nums[i]]++;
//         }
//         int ans = -1;
//         if( k == 1){
//             for(int i= 0;i<n;i++){
//                 if(mp[nums[i]]==1){
//                     ans = max(ans,nums[i]);
//                 }
//             }
//         }

//         for (int i = n - 1; i >=  k; i--) {
//             if (mp[nums[i]] == 1) {

//                 ans = max(ans, nums[i]);
//             }
//         }
//         if (mp[nums[0]] == 1) {

//             ans = max(ans, nums[0]);
//         }

//         return ans;
//     }
// };


class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int n = nums.size();

        // If k == n, there is only one subarray
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        unordered_map<int, int> mp;

        // Frequency of every number
        for (int x : nums) {
            mp[x]++;
        }

        int ans = -1;

        // k == 1
        // Each subarray contains only one element
        if (k == 1) {
            for (auto &p : mp) {
                if (p.second == 1) {
                    ans = max(ans, p.first);
                }
            }
            return ans;
        }

        // For 1 < k < n:
        // Only nums[0] and nums[n-1] can occur in exactly one subarray.
        if (mp[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }

        if (mp[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};

