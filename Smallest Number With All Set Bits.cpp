#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int smallestNumber(int n)
  {
    int d = n;
    string s = "";
    while (n != 0)
    {
      int a = n % 2;
      s += (a + '0');
      n = n / 2;
    }
    reverse(s.begin(), s.end());
    // return s;
    bool flag = false;
    for (int i = 0; i < s.size(); i++)
    {

      if (s[i] == '0')
      {
        flag = true;
        s[i] = '1';
      }
    }
    if (flag == false)
      return d;
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
      ans += (pow(2, i));
    }

    return ans;
  }
};
int main()
{
}