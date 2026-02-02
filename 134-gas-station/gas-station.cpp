class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum =0;
        int tak = 0;
        int b = 0;
        int ans = 0;
        for(int i=0;i<gas.size()-1;i++){
            sum+=gas[i];
            tak+=cost[i];
            b += gas[i];
             b = b -cost[i];
            if(b<0){
                ans = i+1;
                b =0;
            }

        }
        sum+=gas[gas.size()-1];
        tak+=cost[gas.size()-1];
        if(sum<tak) return -1;
        return ans;
    }
};