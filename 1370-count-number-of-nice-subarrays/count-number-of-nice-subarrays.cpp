class Solution {
public:


    int find(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int count = 0;
        int n = nums.size();
        int sum = 0;
        int i = 0;
        int j = 0;
        while (j < n) {
            count += nums[j] % 2;
            while (count > goal) {
                count -= nums[i] % 2;
                i++;
            }
            sum += (j - i + 1);
            j++;
        }
        return sum;
    }


    int numberOfSubarrays(vector<int>& nums, int k) {
        int a = find(nums,k);
        int b = find(nums,k-1);
        return a-b;
    }
};