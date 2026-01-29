class Solution {
public:
    // int f(queue<int>& qu, int k) {
    //     while (qu.size() != 1) {
    //         for (int i = 0; i < k - 1; i++) {
    //             int a = qu.front();
    //             qu.pop();
    //             qu.push(a);
    //         }
    //         qu.pop();
    //     }
    //     return qu.front();
    // }


    int f(vector<int>&ele,int k,int i){
        if(ele.size()==1) return ele[0];
        int d =(i + k -1) % ele.size();
        ele.erase(ele.begin() + d);
        return f(ele,k,d);
    }

    int findTheWinner(int n, int k) {
        // queue<int> qu;
        vector<int>ele;
        for (int i = 1; i <= n; i++) {
            ele.push_back(i);
        }




        return f(ele, k,0);
    }
};
