class Solution {
public:
  string f(string &s, int i, int n, unordered_map<string,int> &mp) {
    if (i == n) {
        if (mp.find(s) == mp.end()) {
            return s;
        }
        return "";
    }

    s[i] = '0';
    string left = f(s, i + 1, n, mp);
    if (left != "") return left;

    s[i] = '1';
    string right = f(s, i + 1, n, mp);
    if (right != "") return right;

    return "";
}

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_map<string,int>mp;
        for(auto e : nums){
            mp[e]++;
        }

    string s(n,' ');
       return f(s, 0, n,mp);
      
    }
};