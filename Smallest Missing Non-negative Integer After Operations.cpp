#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int findSmallestInteger(vector<int> &nums, int value)
  {
    unordered_map<int, int> mp;
    for (int num : nums)
    {
      int r = ((num % value) + value) % value;
      mp[r]++;
    }
    int c = 0;
    while (true)
    {
      if (mp.find((c % value)) != mp.end())
      {
        int r = c % value;
        if (mp[r] > 0)
        {
          mp[c % value]--;
          c++;
        }
        else
          break;
      }
      else
      {
        break;
      }
    }
    return c;
  }
};
int main()
{
}