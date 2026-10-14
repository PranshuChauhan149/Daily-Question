class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        //  if(num == 1 && sum >= 10) return "";
         int s = 0;
         int d = sum;
        string ans = "";
        for(int i =0;i<num;i++){
            for(int j=9;j>=0;j--){
                if(sum >= j){
                    sum-=j;
                    ans+=to_string(j);
                    s+=j;
                    break;
                }
            }
        }
        cout<<s;
        
        if(s != d) {
            return "";
        }
        return ans;
    }
};