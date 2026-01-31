class Solution {
public:
    bool static cmp(vector<int>& a, vector<int>& b) { return a[0] < b[0]; }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), cmp);
        ans.push_back({intervals[0]});
        for (int i = 1; i < intervals.size(); i++) {
            int d = ans.size();
            int a = ans[d - 1][0];
            int b = ans[d - 1][1];
            if (b >= intervals[i][0]) {
                ans[d - 1][0] = min(a, intervals[i][0]);
                ans[d - 1][1] = max(b, intervals[i][1]);
            } else {
                ans.push_back({intervals[i][0], intervals[i][1]});
            }
        }
        return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> ans;
        ans = intervals;
        
        ans.push_back(newInterval);
        return merge(ans);
    }
};