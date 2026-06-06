class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int p = 0;
        int s = 0;
        for(int i =0;i<nums.size();i++){
            s+=nums[i];
        }
        cout<<p<<" "<<s;
        for(int i =0;i<n;i++){
            p+=nums[i];
            s-=nums[i];
            ans[i] = abs((p - nums[i]) - s);
        }
        return ans;
    }
};