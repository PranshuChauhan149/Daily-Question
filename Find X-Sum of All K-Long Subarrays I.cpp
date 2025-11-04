class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k; i++) {
            mp[nums[i]]++;
        }
        for (auto ele : mp) {
            pq.push({ele.second, ele.first});
        }
        int i = 1;
        int j = k;
        int aa = 0;
        for (int i = 0; !pq.empty() && i < x; i++) {
            auto a = pq.top();
            pq.pop();

            aa += a.first * a.second;
        }
        ans.push_back(aa);
        while (j < nums.size()) {
            int a = nums[i - 1];
            mp[a]--;
            if (mp[a] == 0)
                mp.erase(a);
            int b = nums[j];
            mp[b]++;
            pq = priority_queue<pair<int, int>>();

            for (auto ele : mp) {
                pq.push({ele.second, ele.first});
            }
            int aa = 0;
            for (int i = 0; !pq.empty() && i < x; i++) {
                auto a = pq.top();
                pq.pop();

                aa += a.first * a.second;
            }
            i++;
            j++;
            ans.push_back(aa);
        }
        return ans;
    }
};