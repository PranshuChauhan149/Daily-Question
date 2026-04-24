class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int a = 0;
        int b = 0;
        int c =0;
        for(int i =0;i<n;i++){
            if(moves[i] == 'L') a++;
            if(moves[i] == 'R') b++;
            if(moves[i] == '_') c++;
        
        }

        return max(a,b) -min(a,b) +  c;

    }
};