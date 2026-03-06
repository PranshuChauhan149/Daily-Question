class Solution {
public:
int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;
        st.push(n - 1);
        right[n - 1] = n;
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if (st.empty()) {
                right[i] = n;
            } else {
                right[i] = st.top();
            }
            st.push(i);
        }

        left[0] = -1;
        stack<int> s;
        s.push(0);

        for (int i = 1; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            if (s.empty()) {
                left[i] = -1;
            } else {
                left[i] = s.top();
            }
            s.push(i);
        }

        int ans = heights[0] * (right[0] - left[0] - 1);
        for (int i = 1; i < n; i++) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int ans=0;
        for(int i=0;i<r;i++){
            vector<int>heights(c);
            for(int j=0;j<c;j++){
                int h = 0;
                for(int k=i;k>=0;k--){
                    if(matrix[k][j]=='0') break;
                    else h++;
                }
                heights[j] = h;
            }
            ans =  max(ans,largestRectangleArea(heights));

        }
        return ans;
    }
};