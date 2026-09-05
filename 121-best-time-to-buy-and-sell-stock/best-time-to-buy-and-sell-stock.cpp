class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int f = prices[0];
        
        int ans = 0;
        for(int i = 1;i<prices.size();i++){
            f = min(f,prices[i]);
            int a = prices[i] - f;
            ans = max(ans,a);
        }
        return ans;
    }
};