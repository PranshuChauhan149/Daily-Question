class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i=0;
        int j =0;
        int maxL = 0;
        int ans = 0;
        vector<int>hash(26,0);
        while(j<n){
            hash[s[j]-'A']++;
            maxL = max(maxL,hash[s[j]-'A']);
            while((j-i+1) - maxL > k){
                hash[s[i]-'A']--;
                maxL = *max_element(hash.begin(),hash.end());
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};