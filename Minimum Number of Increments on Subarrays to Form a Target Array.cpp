#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int minNumberOperations(vector<int> &target)
  {
    int ans = target[0];
    int n = target.size();
    for (int i = 1; i < n; i++)
    {
      if (target[i - 1] < target[i])
      {
        int a = min(target[i - 1], target[i]);
        ans += target[i] - a;
      }
    }
    return ans;
  }
};
int main()
{
}