class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<int>road(1001,0);
        for(int i=0;i<n;i++){
            road[trips[i][1]] += trips[i][0];
            road[trips[i][2]] -= trips[i][0];
        }
        int sum = 0;
        for(int i=0;i<1001;i++){
            sum+=road[i];
            if(sum>capacity){
                return false;
            }
        }
        return true;
    }
};