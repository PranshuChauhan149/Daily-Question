class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int i = 0; i < asteroids.size(); i++) {
            int d = asteroids[i];
            if (st.empty() || d >= 0) {
                st.push(d);
            } else {
                if (st.top() <= 0) {
                    st.push(d);
                } else {
                    bool flag = false;
                    while (!st.empty() && st.top() > 0) {


                        if (st.top() == abs(d)) {
                            flag = true;
                            st.pop();
                            break;
                        } else if (st.top() < abs(d)) {
                            st.pop();
                        } else {
                            
                            flag = true;
                            break;
                        }
                    }
                    if(!flag){
                        st.push(d);
                    }

                }
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};