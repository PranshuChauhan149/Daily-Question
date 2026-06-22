class Solution {
public:

    bool check(vector<int>&nums,int mid,int k){
        int d = 1;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            if(sum + nums[i]<=mid){
                sum+=nums[i];
            }else{
                sum = nums[i];
                d++;
            }
        }
        if(d<=k) return true;
        return false;
    }


    int splitArray(vector<int>& nums, int k) {
        int l = 0 ;
        int h = 0;
        for(auto ele : nums){
            l =  l = max(l, ele);
            h+=ele;
        }
        int ans = 0;
        while(l<=h){
            int mid = l + (h - l)/2;
            if(check(nums,mid,k)){
                ans=mid;
                h = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return ans;
    }
    
};