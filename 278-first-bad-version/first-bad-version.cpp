// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s =  1;
        int f = n;
        int ans=0;
        while(s<=f){
            long long mid = s + ( f-s)/2;
            if(isBadVersion(mid)){
                ans = mid;
                f = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};