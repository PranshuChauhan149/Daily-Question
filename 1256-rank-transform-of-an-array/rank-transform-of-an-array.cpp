class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.size() == 0)
            return {};

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (int i = 0; i < arr.size(); i++) {
            pq.push({arr[i], i});
        }
        vector<int> ans(arr.size());
        auto count = pq.top();
        ans[count.second] = 1;
        pq.pop();
        int c = 1;
        while (!pq.empty()) {
            auto ele = pq.top();
            if (ele.first == count.first) {
                ans[ele.second] = c;
            } else {
                c++;
                ans[ele.second] = c;
            }
            count = ele;
            pq.pop();
        }
        return ans;
    }
};