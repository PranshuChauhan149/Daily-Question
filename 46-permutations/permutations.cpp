class Solution {
public:

    void f(vector<int>&nums,vector<int>&a,vector<int>&visited,vector<vector<int>>&ans){
        if(a.size()==nums.size()){
            ans.push_back(a);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(!visited[i]){
                visited[i] = 1;
                a.push_back(nums[i]);
                f(nums,a,visited,ans);
                a.pop_back();
                visited[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>visited(n,0);
        vector<int>a;
        f(nums,a,visited,ans);
        return ans;
    }
};