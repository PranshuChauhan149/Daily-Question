class Solution {
public:
    string minWindow(string s, string t) {

        int m = s.size();
        int n = t.size();

        vector<int> freq(256,0);

        for(char c : t)
            freq[c]++;

        int i = 0, j = 0;
        int count = 0;

        int minLen = INT_MAX;
        int start = 0;

        while(j < m){

            if(freq[s[j]] > 0)
                count++;

            freq[s[j]]--;

            while(count == n){

                if(j - i + 1 < minLen){
                    minLen = j - i + 1;
                    start = i;
                }

                freq[s[i]]++;

                if(freq[s[i]] > 0)
                    count--;

                i++;
            }

            j++;
        }

        if(minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};