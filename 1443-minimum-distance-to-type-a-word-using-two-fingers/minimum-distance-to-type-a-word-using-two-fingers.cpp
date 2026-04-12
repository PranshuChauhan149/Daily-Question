class Solution {
public:

    pair<int,int> getCord(char ch){
        int c = ch - 'A';
        return {c/6, c%6};
    }

    int getDistance(int x1,int y1,int x2,int y2){
        if(x1 == -1) return 0; // unused finger
        return abs(x1 - x2) + abs(y1 - y2);
    }

    map<tuple<int,int,int,int,int>, int> dp;

    int solve(string &word,int i,int x1,int y1,int x2,int y2){

        if(i >= word.size()){
            return 0;
        }

        auto key = make_tuple(i,x1,y1,x2,y2);
        if(dp.count(key)) return dp[key];

        auto [x,y] = getCord(word[i]);

        // move finger1
        int moveF1 = getDistance(x1,y1,x,y) +
                     solve(word,i+1,x,y,x2,y2);

        // move finger2
        int moveF2 = getDistance(x2,y2,x,y) +
                     solve(word,i+1,x1,y1,x,y);

        return dp[key] = min(moveF1,moveF2);
    }

    int minimumDistance(string word) {
        return solve(word,0,-1,-1,-1,-1);
    }
};