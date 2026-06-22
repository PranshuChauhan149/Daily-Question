class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> num(150, 0);
        for (int i = 0; i < text.size(); i++) {
            num[text[i] - 'a']++;
        }
        int ans = INT_MAX;
        bool flag = true;

        for (int i = 0; i < num.size(); i++) {
            
            ans = min({num['a' - 'a'], num['b' - 'a'], num['l' - 'a'] / 2,
                       num['o' - 'a'] / 2, num['n' - 'a']});
        }
        return ans;
    }
};