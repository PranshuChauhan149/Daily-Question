class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int d = 0;
        int sum = 0;
        for (int i = 0; i < cost.size(); i++) {
            if (d == 2) {
                d = 0;
                continue;
            }
            sum += cost[i];
            d++;
        }
        return sum;
    }
};