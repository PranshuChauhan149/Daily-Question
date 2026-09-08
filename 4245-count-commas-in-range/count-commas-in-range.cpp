class Solution {
public:
    int countCommas(int n) {
    long long ans=0;
        for(long long i=1000,c=1;i<=n;i*=1000,c++){
            ans+=(n-i+1)*c;
        }
        return ans;
    }
};