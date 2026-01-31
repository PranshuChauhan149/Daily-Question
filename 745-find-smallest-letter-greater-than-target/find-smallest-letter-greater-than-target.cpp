class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
       unordered_map<char,int>mp;
       for(int i=0;i<letters.size();i++){
        mp[letters[i]]++;
       }
       char ch = 'a';
       for(int i=0;i<=26;i++){
        if(mp.find(ch+i)!=mp.end()){
            if(ch+i > target){
                return ch + i;
            }
        }
       }
       return letters[0];
    }
};