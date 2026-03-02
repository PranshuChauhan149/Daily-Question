class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if(st.size()==0) return false;
                char ch2 = st.top();
                if (ch == ')') {
                    if (ch2 != '(')
                        return false;
                }
                else if (ch == '}') {
                    if (ch2 != '{')
                        return false;
                }
                else if (ch == ']') {
                    if (ch2 != '[')
                        return false;
                }
                    st.pop();
                
            }
        }
       return st.size()==0;
        
    }
};