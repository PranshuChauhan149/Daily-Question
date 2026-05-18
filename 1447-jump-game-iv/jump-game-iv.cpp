class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        if (n <= 1) {
            return 0;
        }

        unordered_map<int, vector<int>> graph;

        // Store indices having same value
        for (int i = 0; i < n; i++) {
            graph[arr[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);

        vector<bool> visited(n, false);
        visited[0] = true;

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            // Process current BFS level
            while (size--) {
                int node = q.front();
                q.pop();

                // Reached last index
                if (node == n - 1) {
                    return steps;
                }

                // Jump to same value indices
                for (int child : graph[arr[node]]) {
                    if (!visited[child]) {
                        visited[child] = true;
                        q.push(child);
                    }
                }

                // Clear to avoid redundant processing
                graph[arr[node]].clear();

                // Move to node + 1
                if (node + 1 < n && !visited[node + 1]) {
                    visited[node + 1] = true;
                    q.push(node + 1);
                }

                // Move to node - 1
                if (node - 1 >= 0 && !visited[node - 1]) {
                    visited[node - 1] = true;
                    q.push(node - 1);
                }
            }

            steps++;
        }

        return -1;
    }
};