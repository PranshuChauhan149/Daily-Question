class StockSpanner {
public:

   vector<int>ans;

    StockSpanner() {
        
    }
    
    int next(int price) {
        if(ans.size()==0){
            ans.push_back(price);
            return 1;
        }
        int c = 1;
       for(int i=ans.size()-1;i>=0;i--){
        if(ans[i]<=price) c++;
        else break;
       }
       ans.push_back(price);
       return c;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */