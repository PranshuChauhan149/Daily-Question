class Solution {
public:
    set<vector<int>> st;
    void f(vector<int>& candidates, int i, int target, vector<int>& a,
           vector<vector<int>>& ans) {
        
        if (target == 0) {
      
            if (!st.count(a)) {
                ans.push_back(a);
                st.insert(a);
            }
            return;
        }

if (i >= candidates.size())
            return;

        if (candidates[i] <= target) {
            a.push_back(candidates[i]);
            f(candidates, i + 1, target - candidates[i], a, ans);
            a.pop_back();
        }
        int idx = i+1;
        while(idx<candidates.size() && candidates[idx]==candidates[i]) idx++;
        f(candidates, idx, target, a, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> a;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        f(candidates, 0, target, a, ans);
        return ans;
    }
};