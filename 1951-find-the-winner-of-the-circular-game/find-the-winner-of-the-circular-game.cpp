class Solution {
public:

    int f(queue<int>&qu,int k){
        while(qu.size()!=1){
            for(int i=0;i<k-1;i++){
            int a = qu.front();
            qu.pop();
            qu.push(a);
            }
            qu.pop();
        }
        return qu.front();


    }

    int findTheWinner(int n, int k) {
        queue<int>qu;
        for(int i=1;i<=n;i++){
            qu.push(i);
        }
        return f(qu,k);

    }
};