class Solution {
public:
    int binaryGap(int n) {
        int ans =0;
        int b =-1;
        int i =0;
        while(n!=0){
            int r = (n&1);
            if(r && b==-1){
                b = i;
            }
            else if(r){
                ans = max(ans, i - b);
                 b = i;  
            }
            i++;
             n= n>>1;

        }
        return ans;
    }
};