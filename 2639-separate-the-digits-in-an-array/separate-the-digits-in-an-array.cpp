class Solution {
public:

    void fill(string str,vector<int>&ans){
        for(auto ele : str){
            ans.push_back(ele - '0');
        }
    }

    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i =0;i<n;i++){
            string str = to_string(nums[i]);
            fill(str,ans);
        }
        return ans;
    }
};