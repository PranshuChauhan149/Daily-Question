class Solution {
public:
    int f(int n) {
        int sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minElement(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for (auto e : nums) {
            ans = min(ans, f(e));
        }
        return ans;
    }
};