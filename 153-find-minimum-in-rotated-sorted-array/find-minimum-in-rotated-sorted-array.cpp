class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int s = 0;
        int e = nums.size() - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            // if(nums[s]>nums[mid] && nums[mid]<nums[e]) return nums[mid];
            if (nums[s] <= nums[mid] && nums[mid] < nums[e]) {
                e = mid - 1;
            } else if (nums[s] <= nums[mid] && nums[mid] > nums[e]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return nums[s];
    }
};