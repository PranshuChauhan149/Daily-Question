class Solution {
public:
    int beautySum(string s) {
       int n = s.size();
        int ans = 0;
        for(int i =0;i<n;i++){
            vector<int>a(26,0);
            for(int j = i;j<n;j++){
           int mi = INT_MAX;
            int ma = 0;
                int d = s[j] - 'a';
                a[d]++;
                for(int k =0;k<26;k++){
                    if(a[k] > 0){
                    mi = min(mi,a[k]);
                    ma = max(ma,a[k]);
                    }
                }
              
                
                ans += (ma-mi);
            }
        }
        return ans;
    }
};