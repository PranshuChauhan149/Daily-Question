class Solution {
public:

     pair<int,int> find(vector<int>&nums){
        int first = nums[1];
        int idx = 1;
        int sec = INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(first>nums[i]){
           first =  min(first,nums[i]);
            idx = i;
            }
            
        }
        for(int i=1;i<nums.size();i++){
            if(idx!=i){
                sec = min(sec,nums[i]);
            }
        }
        return {first,sec};
        
    }

    int minimumCost(vector<int>& nums) {
        pair<int,int>ele = find(nums);
        return nums[0] + ele.first + ele.second;
    }
};