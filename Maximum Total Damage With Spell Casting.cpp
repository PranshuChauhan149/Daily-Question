#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<long long> dp;
  unordered_map<long long, long long> mp;

  long long f(vector<long long> &nums, int i)
  {
    if (i >= nums.size())
      return 0;
    if (dp[i] != -1)
      return dp[i];
    long long skip = f(nums, i + 1);
    long long j = lower_bound(nums.begin() + i + 1, nums.end(), nums[i] + 3) - nums.begin();
    long long take = nums[i] * mp[nums[i]] + f(nums, j);
    return dp[i] = max(skip, take);
  }

  long long maximumTotalDamage(vector<int> &power)
  {
    mp.clear();
    for (int i = 0; i < power.size(); i++)
    {
      mp[power[i]]++;
    }
    vector<long long> nums;
    for (auto &ele : mp)
    {
      nums.push_back(ele.first);
    }
    int n = nums.size();
    dp.clear();
    dp.assign(n + 1, -1);
    sort(nums.begin(), nums.end());

    return f(nums, 0);
  }
};

int main()
{
}