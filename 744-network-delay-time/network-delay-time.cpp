class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       
        vector<vector<pair<int,int>>> graph(n+1);
        for (auto e : times) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            graph[u].push_back({v, w});
        }
    
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        pq.push({0, k});
        while (!pq.empty()) {
            auto ele = pq.top();
            pq.pop();
            int cost = ele.first;
            int node = ele.second;
            if (cost > dist[node]) continue;
            for (auto it : graph[node]) {
                int wt = it.second;
                int val = it.first;
                if (cost + wt < dist[val]){
                    dist[val] = wt + cost;
                    pq.push({wt + cost, val});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
    if (dist[i] == 1e9)
        return -1;
    ans = max(ans, dist[i]);
}
        return ans;
    }
};