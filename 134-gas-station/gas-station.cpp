class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tak = 0;
        int cos = 0;
        int b = 0;
        int ans = 0;
        int n = gas.size();
        for (int i = 0; i < n - 1; i++) {
            tak += gas[i];
            cos += cost[i];
            b += gas[i];
            b -= cost[i];
            if (b < 0) {
                ans = i + 1;
                b =0;
            }
        }
        tak += gas[n - 1];
        cos += cost[n - 1];

        if (tak < cos)
            return -1;
        return ans;
    }
};