class Solution {
public:
    bool check(vector<vector<int>>& tasks, int mid) {
        int n = tasks.size();
        for (int i = n - 1; i >= 0; i--) {
            if (mid >= tasks[i][1]) {
                mid -= tasks[i][0];
            }else{
                return false;
            }
        }
        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(),
             [&](vector<int>& a, vector<int>& b) { 
                
                int d1 = a[1] - a[0];
                int d2 = b[1] - b[0];
                return d1 < d2;

              });

        int low = 0;
        int high = 0;
        for (auto ele : tasks) {
            high += ele[1];
        }
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(tasks, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};