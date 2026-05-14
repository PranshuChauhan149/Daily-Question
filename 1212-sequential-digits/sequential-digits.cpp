class Solution {
public:

    void f(int i,int low,int high,vector<int>&ans,int num){
        if(num > high) return;
        if(num>= low && num<=high){
            ans.push_back(num);
        }
        if(i > 9) return ;
        f(i+1,low,high,ans,num*10+i);
    }


    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
            f(i,low,high,ans,0);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};