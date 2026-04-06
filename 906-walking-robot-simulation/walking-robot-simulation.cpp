class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<string> st;
        for (int i = 0; i < obstacles.size(); i++) {
            int a = obstacles[i][0];
            int b = obstacles[i][1];
            string str = to_string(a) + "_" + to_string(b);
            st.insert(str);
        }
        int x = 0;
        int y = 0;
        int ans = 0;

        pair<int, int> p = {0, 1};
        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -2) {
                p = {-p.second, p.first};
            } else if (commands[i] == -1) {
                p = {p.second, -p.first};
            } else {
                for (int j = 0; j < commands[i]; j++) {
                    int newx = x + p.first;
    int newy = y + p.second;

                    string str = to_string(newx) + "_" + to_string(newy);
                    if (st.count(str)) {
                        break;
                    }

                    x = newx;
                    y = newy;
                }
            }
            ans = max(ans, x * x + y * y);
        }

        return ans;
    }
};