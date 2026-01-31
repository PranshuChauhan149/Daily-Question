bool cmp(vector<int>&a,vector<int>&b){
    return a[0]<b[0];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end(),cmp);
        vector<vector<int>>result;
        result.push_back(points[0]);
        for(int i=1;i<n;i++){
            vector<int>curr = points[i];
            if(result[result.size()-1][1]>=curr[0]){
                result[result.size()-1][0] = min(result[result.size()-1][0],curr[0]);
                result[result.size()-1][1] = min(result[result.size()-1][1],curr[1]);
            }
            else{
                result.push_back(points[i]);
            }
        }
    return result.size();
    }
};