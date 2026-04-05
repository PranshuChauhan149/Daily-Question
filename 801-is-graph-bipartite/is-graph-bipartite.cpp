class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, int col,
             vector<int>& color) {
        
        color[node] = col;

        for (auto nei : graph[node]) {
            if (color[nei] == -1) {
                
                if (!dfs(graph, nei, 1 - col, color)) {
                    return false;
                }
            } 
            else if (color[nei] == col) {
                
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!dfs(graph, i, 0, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};