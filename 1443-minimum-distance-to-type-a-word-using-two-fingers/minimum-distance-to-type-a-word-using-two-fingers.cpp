class Solution {
public:

    pair<int,int> getCord(char ch){
        int c = ch - 'A';
        return {c / 6, c % 6};
    }

    int getDistance(int x1,int y1,int x2,int y2){
        if(x1 == -1) return 0; // finger not used yet
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int dp[301][27][27]; // memo table

    int solve(string &word,int i,int f1,int f2){
        if(i == word.size()) return 0;

        if(dp[i][f1+1][f2+1] != -1)
            return dp[i][f1+1][f2+1];

        int curr = word[i] - 'A';

        auto [x,y] = getCord(word[i]);

        // finger1 move
        int cost1 = getDistance(
            (f1==-1 ? -1 : getCord(f1+'A').first),
            (f1==-1 ? -1 : getCord(f1+'A').second),
            x,y
        ) + solve(word,i+1,curr,f2);

        // finger2 move
        int cost2 = getDistance(
            (f2==-1 ? -1 : getCord(f2+'A').first),
            (f2==-1 ? -1 : getCord(f2+'A').second),
            x,y
        ) + solve(word,i+1,f1,curr);

        return dp[i][f1+1][f2+1] = min(cost1,cost2);
    }

    int minimumDistance(string word) {
        memset(dp,-1,sizeof(dp));
        return solve(word,0,-1,-1);
    }
};