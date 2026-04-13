class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int r = graph.size();
        vector<int> indegree(r, 0);
        vector<vector<int>> g(r);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                int v = graph[i][j];
                g[v].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> qu;
        for (int i = 0; i < r; i++) {
            if (indegree[i] == 0) {
                qu.push(i);
            }
        }
        vector<int> ans;
        while (!qu.empty()) {
            int val = qu.front();
            qu.pop();
            ans.push_back(val);
            for (auto d : g[val]) {
                indegree[d]--;
                if (indegree[d] == 0) {
                    qu.push(d);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};