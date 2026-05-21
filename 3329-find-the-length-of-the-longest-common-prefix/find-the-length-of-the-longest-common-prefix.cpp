class Solution {
public:
    void f(int num, set<int>& st) {

        while (num > 0) {
            st.insert(num);
            num /= 10;
        }
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        set<int> st;
        for (int i = 0; i < n; i++) {
            f(arr1[i], st);
        }

        int m = arr2.size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int num = arr2[i];
            while (num > 0) {
                if (st.count(num)) {
                    ans = max(ans, (int)to_string(num).size());
                }
                num /= 10;
            }
        }
        return ans;
    }
};