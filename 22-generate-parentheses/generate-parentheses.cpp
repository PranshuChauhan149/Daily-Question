class Solution {
public:

    void f(string &s,vector<string>&ans,int left,int right){
        if(left==0 && right==0){
            ans.push_back(s);
            return ;
        }
        if(left > 0){
        s+='(';
        f(s,ans,left-1,right);
        s.pop_back();
        }
        if(right > left){
        s+=')';
        f(s,ans,left,right-1);
        s.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
       
        string s = "";
        vector<string>ans;
        f(s,ans,n,n);
        return ans;
    }
};