class Solution {
public:

    bool check (int n){
      
        bool change = false;
        while(n!=0){
            int r = n % 10 ;
            if(r == 3 || r == 4 || r == 7 ) return false;
            if(r == 2 || r==5 || r==6 || r==9) change = true;
            n /= 10;
        }
        return change;
    }

    int rotatedDigits(int n) {
        int ans = 0;
        for(int i =1;i<=n;i++){
            if(check(i)){
                ans++;
            }
        }
        return ans;
    }
};