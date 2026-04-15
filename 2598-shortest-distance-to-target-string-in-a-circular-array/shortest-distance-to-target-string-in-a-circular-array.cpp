class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        
        if(words[startIndex] == target) return 0;

        int c = 1;
        int s = (startIndex + 1) % n;
        int e = (startIndex - 1 + n) % n;

        while(s != startIndex) {   
            if(words[s] == target) return c;
            if(words[e] == target) return c;

            s = (s + 1) % n;           
            e = (e - 1 + n) % n;      
            c++;
        }

        return -1;
    }
};