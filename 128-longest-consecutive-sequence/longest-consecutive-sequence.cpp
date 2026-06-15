class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto ele : nums) {
            mp[ele]++;
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int ele = nums[i];
            int c = 1;

            while (true) {
                if(mp.find(ele - 1)!=mp.end()){
                    mp.erase(ele -1);
                    ele --;
                    c++;

                }
                else break;
            }
            ele = nums[i];
            while (true) {
                if(mp.find(ele + 1)!=mp.end()){
                    mp.erase(ele + 1);
                    ele ++;
                    c++;
                }
                else break;
            }
            ans = max(ans,c);
        }
        return ans;
    }
};