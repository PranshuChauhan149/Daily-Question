class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n - 1] != '0')
            return false;
        queue<int> qu;
        qu.push(0);
        vector<bool> visited(n, 0);
          int farthest = 0;
        visited[0] = 1;
        while (!qu.empty()) {
            auto ele = qu.front();
            qu.pop();
            int i = ele;
           
             int d1 = max(i + minJump, farthest + 1);
            int d2 = min(i + maxJump, n - 1);
          
            for (int j = d1; j <= d2 && j<n; j++) {
                if (s[j] == '0' && !visited[j]) {
                     visited[j] = 1;
                    if (j == n - 1)
                        return true;
                    qu.push(j);
                }
            }
                  farthest = d2;
        }
        return false;
    }
};