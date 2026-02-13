class Solution {
public:

    void f(int idx,int n,int k,vector<vector<int>>&ans,vector<int>&a){
        
        if(a.size()==k){
            ans.push_back(a);
            return ;
        }
        for(int i = idx;i<=n;i++){
            a.push_back(i);
            f(i+1,n,k,ans,a);
            a.pop_back();
        }
    }


    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>a;
        f(1,n,k,ans,a);
        return ans;
    }
};