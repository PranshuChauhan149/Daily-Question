class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums1[i] == nums2[j]) {
                    int k = i;
                    int l = j;
                    int a = 0;
                    while (k < n && l < m) {
                        if (nums1[k++] == nums2[l++]) {
                            a++;
                            ans = max(ans, a);
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};