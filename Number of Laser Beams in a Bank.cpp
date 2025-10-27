class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int ans = 0;
        for (int i = 0; i < bank.size(); i++) {
            int curr = 0;
            string str = bank[i];
            for (int j = 0; j < bank[i].size(); j++) {
                if (str[j] == '1') {
                    curr++;
                }
            }

            ans += prev * curr;
            if (curr != 0) {

                prev = curr;
            }
        }
        return ans;
    }
};