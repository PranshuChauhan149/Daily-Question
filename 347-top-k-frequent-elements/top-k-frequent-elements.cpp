class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for (auto& e : mp) {
            pq.push({e.second, e.first});
        }
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};