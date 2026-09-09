class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        for(long long i=1000,c =1;i<=n;i*=1000,c++){
            long long u = min(n,i*1000-1);
            
            ans += (u-i+1)*c;
        }
        return ans;
    }
};