class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> arr(n);
        arr[n - 1] = -1;
        stack<int> st;
        st.push(nums2[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && nums2[i] >= st.top())
                st.pop();
            if (st.empty()) {
                arr[i] = -1;
            } else {
                arr[i] = st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums2[i]] = arr[i];
        }
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};