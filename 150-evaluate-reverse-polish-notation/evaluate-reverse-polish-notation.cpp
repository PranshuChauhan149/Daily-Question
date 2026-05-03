class Solution {
public:

    int solve(int num1,int num2,string ch){
        if(ch == "+") return num2 + num1;
        if(ch == "/") return num2 / num1;
        if(ch == "-") return num2 - num1;
      return num2*num1;
    }

    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        int n=  tokens.size();
        for(int i=0;i<n;i++){
            string ch = tokens[i];
            if(ch == "+" || ch=="-" || ch == "*" || ch == "/"){
                int num1 = stoi(st.top());
                st.pop();
                int num2 = stoi(st.top());
                st.pop();
                int ans = solve(num1,num2,ch);
                st.push(to_string(ans)); 

            }
            else{
                st.push(ch);
            }
        }
    return stoi(st.top());
    }
};