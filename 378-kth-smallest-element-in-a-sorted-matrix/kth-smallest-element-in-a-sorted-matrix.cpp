class Solution {
public:
    int kthSmallest(vector<vector<int>>& arr, int k) {
        priority_queue<int>pq;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++){
            pq.push(arr[i][j]);
            if(pq.size() > k) pq.pop();
            }
        }
        return pq.top();
    }
};