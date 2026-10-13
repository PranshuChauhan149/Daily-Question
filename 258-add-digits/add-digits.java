class Solution {


int sum(int n){
    int ans = 0;
    while(n != 0){
        int d = n%10;
        ans += d;
        n/=10;
    }
    return ans;
}

    public int addDigits(int num) {
        if(num < 10) return num;
        return addDigits(sum(num));
    }
}