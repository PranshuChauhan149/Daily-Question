class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
         int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        while (i < n) {
            int a = nums[i];
            int j = i + 1;
        
            int k = n - 1;
            while (j < k) {
                int b = nums[j];
                int c = nums[k];
                int sum = a + b + c;
                 if (sum == target)
                    return sum;
                
                 if (abs(target - sum) < abs(target - ans)) {
                    ans = sum;
                }

               
                if (sum < target) {
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