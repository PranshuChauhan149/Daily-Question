class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size()) return "0";
        stack<char>st;
        int n = num.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && st.top() > num[i]){
                st.pop();
                k--;
            }
           if(!st.empty() || num[i]!='0' ) st.push(num[i]);
            
        }
        if(k!=0){
            while(!st.empty() && k--){
                st.pop();
            }
        }
        string ans = "";
        while(!st.empty()){
            
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans=="") return "0";
        return ans;
    }
};