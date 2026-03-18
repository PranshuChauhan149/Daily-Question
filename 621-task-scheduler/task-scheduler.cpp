class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        int time = 0;
        vector<int> a(26, 0);
        for (int i = 0; i < tasks.size(); i++) {
            a[tasks[i] - 'A']++;
        }
        for (int i = 0; i < 26; i++) {
            if (a[i] > 0) {
                pq.push(a[i]);
            }
        }
        while (!pq.empty()) {
                vector<int> b;
            for (int i = 0; i < n + 1; i++) {
                if (!pq.empty()) {
                    int temp = pq.top();
                    pq.pop();
                    temp--;
                    b.push_back(temp);
                }
            }

            for (auto &e : b) {
                if (e > 0) {
                    pq.push(e);
                }
            }
            if (pq.empty()) {
                time += b.size();
            } else {
                time += n + 1;
            }
        }
        return time;
    }
};