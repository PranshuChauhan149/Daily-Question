class Solution {
public:
    bool check(vector<int>& weights, int mid, int days) {
        int sum = 0;
        int d = 1;
        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] <= mid) {
                sum += weights[i];
            } else {
                d++;
                sum = weights[i];
            }
        }
        if (d <= days)
            return true;

        return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
       int l = *max_element(weights.begin(), weights.end());
        int h = 0;
        for (int i = 0; i < weights.size(); i++) {
            h += weights[i];
        }
        int ans = h;
        while (l <= h) {
            int mid = (l + h) / 2;

            if (check(weights, mid, days)) {
                ans = min(ans, mid);

                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};