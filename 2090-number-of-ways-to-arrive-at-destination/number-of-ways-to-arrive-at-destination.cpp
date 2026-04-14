class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> graph(n);
        for (auto r : roads) {
            int u = r[0];
            int v = r[1];
            int w = r[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

       priority_queue<pair<long long, int>,
               vector<pair<long long, int>>,
               greater<pair<long long, int>>> pq;
        vector<int> ways(n, 0);
        vector<long long> dist(n, 1e18);
        ways[0] = 1;
        dist[0] = 0;
        pq.push({0, 0});
        int mod = (int)(1e9 + 7);
        while (!pq.empty()) {
            auto ele = pq.top();
            pq.pop();
            long long cost = ele.first;
            long long node = ele.second;
            if (cost > dist[node])
                continue;
            for (auto d : graph[node]) {
                long long dis = d.first;
                long long val = d.second;
                if (val + cost < dist[dis]) {
                    dist[dis] = cost + val;
                    pq.push({dist[dis], dis});
                    ways[dis] = ways[node];
                } else if (val + cost == dist[dis]) {
                    ways[dis] = (ways[dis] + ways[node]) % mod;
                }
            }
        }

        return (ways[n - 1]) % mod;
    }
};