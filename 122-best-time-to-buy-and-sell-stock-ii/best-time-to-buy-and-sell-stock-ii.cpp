class Solution {
public:


    int f(vector<int>&prices,int i,int buy,vector<vector<int>>&dp){
        if(i==prices.size()) return 0;
        int a;

        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy==1){
            int t  = -prices[i] + f(prices,i+1,0,dp);
            int nt =  0 + f(prices,i+1,1,dp);
            a  = max(t,nt);
        }
        else {
             int t  = prices[i] + f(prices,i+1,1,dp);
            int nt =  0 + f(prices,i+1,0,dp);
            a = max(t,nt);
        }

        return dp[i][buy] =  a;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
    //  return f(prices,0,1,dp);   
int n = prices.size();
 for (int i = n - 1; i >= 0; i--) {
         
        
            int t  = -prices[i] + dp[i+1][0];
            int nt =  0 +dp[i+1][1];
           int  a  = max(t,nt);
        

        
             int tt  = prices[i] + dp[i+1][1];
            int ntt =  0 + dp[i+1][0];
           int  b = max(tt,ntt);
            
    
         dp[i][1] =  a;
         dp[i][0] =  b;
    }
     return dp[0][1];

    }
};