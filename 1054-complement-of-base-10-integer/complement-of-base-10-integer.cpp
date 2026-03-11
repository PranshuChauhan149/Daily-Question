class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        string str = "";
        while (n != 0) {
            int r = n & 1;
            if (r == 1) {
                str += '0';
            } else {
                str += '1';
            }
            n = n >> 1;
        }
        int ans = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '1') {
                ans += pow(2, i);
            }
        }
        return ans;
    }
};