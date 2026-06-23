class Solution {
public:
   static bool cmp(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0])
        return a[1] > b[1];

    return a[0] < b[0];
}

    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<vector<int>> arr(n, vector<int>(2, 0));
        for (auto ele : nums) {
            mp[ele]++;
        }
        int i = 0;
        for (auto e : mp) {
            arr[i][0] = e.second;
            arr[i][1] = e.first;
            i++;
        }
        int ans = 0;
        sort(arr.begin(), arr.end(), cmp);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < arr[i][0]; j++) {
                nums[ans++] = arr[i][1];
            }
        }
        return nums;
    }
};