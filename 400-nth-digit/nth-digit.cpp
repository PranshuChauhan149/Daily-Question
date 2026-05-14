class Solution {
public:
    int findNthDigit(int n) {
        long long f = 1;
        long long d = 9;
        long long l = 1;
        while(n > d*l){
            n-=d*l;
            d = d*10;
            f = f*10;
            l++;
        }
        long long dd = f + (n-1) / l;
        string str = to_string(dd);
        long long idx = (n-1)%l;

        return str[idx] - '0';



    }
};