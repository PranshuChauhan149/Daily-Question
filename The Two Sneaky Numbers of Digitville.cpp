#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> getSneakyNumbers(vector<int> &nums)
  {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
      mp[nums[i]]++;
    }
    vector<int> ans;
    for (auto ele : mp)
    {
      if (ele.second == 2)
        ans.push_back(ele.first);
    }
    return ans;
  }
};
int main()
{
}