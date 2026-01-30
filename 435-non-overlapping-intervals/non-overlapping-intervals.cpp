class Solution {
public:

    bool static cmp(vector<int>&a,vector<int>&b){
        return a[1] < b[1];
    }
    int c =0;
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int n = intervals.size();
        int prev = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=prev){
                prev = intervals[i][1];
            }
            else c++;
        }
        return c;
    }
};