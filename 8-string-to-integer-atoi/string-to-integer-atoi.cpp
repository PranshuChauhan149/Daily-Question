class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        bool flag = false;
        int i = 0;
        while (s[i] == ' ')
            i++;
      if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') {
                flag = true;
            }
            i++;
        }

        long long ans = 0;
        while (i < n) {
            char ch = s[i];
            if (isdigit(ch)) {
                ans = ans * 10 + (ch - '0');
                if (!flag && ans > INT_MAX) {
                return INT_MAX;
            }

            if (flag && -ans < INT_MIN) {
                return INT_MIN;
            }
            } else {
                break;
            }
            i++;
        }
        if (flag) {
            ans = ans * -1;
        }
        return ans;
    }
};