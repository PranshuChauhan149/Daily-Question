class Solution {
public:
 void f(vector<int>&arr,int i,vector<vector<int>>&ans,vector<int>&a){
        
        if(i == arr.size()){
            ans.push_back(a);
            return ;
        }
        if(i>arr.size()) return ;
        a.push_back(arr[i]);
        f(arr,i+1,ans,a);
        a.pop_back();
        int idx = i+1;
        while(idx < arr.size() && arr[idx] == arr[i]){
            idx = idx + 1;
        }
        f(arr,idx,ans,a);
    }
  
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
         sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        vector<int>a;
        f(arr,0,ans,a);
        return ans;
    }
};