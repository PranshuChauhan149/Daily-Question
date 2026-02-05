class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                int d = nums[i] % n;
                ans[i] = nums[(d+i)%n];
            }
            else if(nums[i]<0){
                int d = abs(nums[i])%n;
                int dd = n-1 - d;
                cout<<dd;
                ans[i] = nums[(i+dd+1)%n];
            }
            else {
                ans[i] = nums[i];
            }
        }
        return ans;
        
    }
};