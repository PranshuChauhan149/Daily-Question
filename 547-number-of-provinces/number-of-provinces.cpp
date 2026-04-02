class Solution {
public:
    // void dfs(vector<vector<int>> graph, int i, vector<int>& visited) {
    //     visited[i] = 1;
    //     for (auto e : graph[i]) {
    //         if (!visited[e]) {
    //             dfs(graph, e, visited);
    //         }
    //     }
    // }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int r = isConnected.size();
        int c = isConnected[0].size();

        vector<vector<int>> graph(r);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (i != j && isConnected[i][j] == 1) {
                    graph[i].push_back(j);
                }
            }
        }

        vector<int> visited(r, 0);
        int count = 0;

        for (int i = 0; i < r; i++) {
            queue<int>qu;
            if(!visited[i]){
                count++;
                qu.push(i);

                while(!qu.empty()){
                    int d = qu.front();
                    qu.pop();
                    visited[d] = 1;
                    for(auto e : graph[d]){
                        if(!visited[e]){
                            qu.push(e);
                        }
                    }
                }
            }
        
        }
        return count;
    }
};