class Solution {
public:
    // void f(int n,vector<int>&ans,int i){
    //     if(i>n){
    //         return;
    //     }
    //     if(i<=n && i!=0){
    //         ans.push_back(i);
    //     }
    //     if(i!=0){
    //         for(int j=0;j<=9;j++){

    //             f(n,ans,i*10+j);
    //         }
    //     }else{
    //           for(int j=1;j<=9;j++){
    //             f(n,ans,i*10+j);
    //         }
    //     }
          
    // }

    void f(int n,vector<int>&ans,int i){

            if(i>n) return ;
            if(i<= n && i!=0){
                ans.push_back(i);
            }

            if(i!=0){
                for(int j=0;j<=9;j++){
                    f(n,ans,i*10+j);
                }
            }
            else {
                 for(int j=1;j<=9;j++){
                  f(n,ans,i*10+j);
                }
            }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        f(n,ans, 0);
        return ans;
    }
};