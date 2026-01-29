class Solution {
public:
    void f(vector<string>& arr, string digits, int i, vector<string>& ans,
           string& str) {

        if (i >= digits.size()) {
            ans.push_back(str);
            return;
        }

        char ch = digits[i];
        int idx = ch - '0';
        string a = arr[idx - 1];
        for (int k = 0; k < a.size(); k++) {
            str += a[k];
            f(arr, digits, i + 1, ans, str);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> arr = {"",    "abc",  "def", "ghi", "jkl",
                              "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string str = "";
        f(arr, digits, 0, ans, str);
        return ans;
    }
};