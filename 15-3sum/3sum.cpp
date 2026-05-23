class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        set<vector<int>> st;
        vector<vector<int>> ans;
        while (i < n) {
            int j = i + 1;
            int k = n - 1;
            int a = nums[i];
            while (j < k) {
                int b = nums[j];
                int c = nums[k];
                int sum = a + b + c;
                if (sum == 0) {
                    if (!st.count({a, b, c})) {
                        ans.push_back({a, b, c});
                        st.insert({a,b,c});
                    }
                    j++;
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
            i++;
        }
        return ans;
    }
};