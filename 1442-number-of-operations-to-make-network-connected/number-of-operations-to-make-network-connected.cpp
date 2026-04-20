class Solution {
public:

    void dfs(int node,vector<vector<int>>&graph,vector<int>&visited){
        visited[node] = 1;
        for(auto d : graph[node]){
            if(!visited[d]){
                dfs(d,graph,visited);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) return -1;
        vector<vector<int>>graph(n);
    
        for(auto e : connections){
            int u = e[0];
            int v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
           
        }
        int c =0;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                c++;
                dfs(i,graph,visited);
            }
        }
        for(int i=0;i<n;i++){
            cout<<visited[i]<<" ";
        }
        return c-1;
    }
};