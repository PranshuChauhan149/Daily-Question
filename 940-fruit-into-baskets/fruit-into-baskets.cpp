class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int n = fruits.size();
        int j = 0;
        int i = 0;
        int ans = 1;
        while (j < n) {
            mp[fruits[j]]++;

            
           while(mp.size() > 2){
            mp[fruits[i]]--;
            if(mp[fruits[i]]==0){
                mp.erase(fruits[i]);
            }
            i++;
           }

           if (mp.size() == 2) {
                int a = 0;
                for (auto e : mp) {
                    a += e.second;
                }
                ans = max(ans, a);
            }
            j++;
        }

                int a = 0;
                for (auto e : mp) {
                    a += e.second;
                }
                ans = max(ans, a);
            
        return ans;
    }
};