class Solution {
public:


    int doubleCount(string s, char a, char b) {
        unordered_map<int, int> mp;
           mp[0] = -1; 
        int count1 = 0;
        int count2 = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != a && s[i] != b) {
                mp.clear();
                count1 = 0;
                count2 = 0;
            } else {
                if (s[i] == a) {
                    count1++;
                }
                if (s[i] == b) {
                    count2++;
                }
                if (count1 == count2) {
                    ans = max(ans, count1 + count2);
                }
                int diff = count1 - count2;
                if (mp.find(diff) != mp.end()) {
                    ans = max(ans, i - mp[diff]);
                } else {
                    mp[diff] = i;
                }
            }
        }
        return ans;
    }

   

    int longestBalanced(string s) {
         int ans = 0;
        int count = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            ans = max(count, ans);
            } else {
                count = 1;
            }
        }
        ans = max(ans,count);

        ans = max(ans,doubleCount(s,'a','b'));
        ans = max(ans,doubleCount(s,'b','c'));
        ans = max(ans,doubleCount(s,'a','c'));

    


        int count1 =0;
        int count2 =0;
        int count3 =0;
    unordered_map<string,int>mpp;
          mpp["0_0"] = -1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                count1++;
            }
            if(s[i]=='b'){
                count2++;
            }
            if(s[i]=='c'){
                count3++;
            }
            if(count1==count2 && count2==count3){
                 ans = max(ans, count1 + count2);
            }
            int diff1 = count1 - count2;
            int diff2 = count1 - count3;
            string key = to_string(diff1) + "_" + to_string(diff2);
            if(mpp.count(key)){
                ans = max(ans,i-mpp[key]);
            }
            else{
                mpp[key] = i;
            }
            
        }
        return ans;
    }
};