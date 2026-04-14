class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>>graph(n);
        for(auto f : flights){
            int u = f[0];
            int v = f[1];
            int w = f[2];
            graph[u].push_back({v,w});
        }
        queue<pair<int,pair<int,int>>>qu;
        qu.push({0,{src,0}});
        vector<int>dist(n,1e9);
        dist[src] = 0;
        while(!qu.empty()){
            auto ele = qu.front();
            qu.pop();
            int stop = ele.first;
            int node = ele.second.first;
            int wt = ele.second.second;
            if(stop > k) continue;
            for(auto e : graph[node]){
                int it = e.first;
                int dis = e.second;
                if(wt + dis <= dist[it] && stop <= k){
                    dist[it] = wt + dis;
                    qu.push({stop+1,{it,wt+dis}});
                }
            }

        }
        if(dist[dst] == 1e9){
            return -1;
        }
        return dist[dst];
    }
};