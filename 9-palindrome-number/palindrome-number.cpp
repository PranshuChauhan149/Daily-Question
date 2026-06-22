class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string str = to_string(x);
        reverse(str.begin(),str.end());
        if(str==s) return true;
        return false;
    }
};