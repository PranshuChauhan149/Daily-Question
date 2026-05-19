class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int p = 1;
        int s = 1;
     
        for (int i = 0; i < nums.size(); i++) {
            if( p==0) p=1;
            if(s == 0) s =1;
            p*=nums[i];
            s*=nums[nums.size()-i-1];
            ans = max(ans,max(p,s));
        }
        return ans;
    }
};