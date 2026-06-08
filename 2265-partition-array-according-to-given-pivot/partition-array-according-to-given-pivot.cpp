class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> a;
        vector<int> b;
        vector<int> ans;
        int n = nums.size();
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                a.push_back(nums[i]);
            } else if (nums[i] == pivot) {
                c++;
            }

            else {
                b.push_back(nums[i]);
            }
        }
        for (int i = 0; i < a.size(); i++) {
            ans.push_back(a[i]);
        }
        for (int i = 0; i < c; i++) {
            ans.push_back(pivot);
        }
        for (int i = 0; i < b.size(); i++) {
            ans.push_back(b[i]);
        }
        return ans;
    }
};