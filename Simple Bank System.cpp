#include <bits/stdc++.h>
using namespace std;
class Bank
{
public:
  vector<long long> det;
  int n;
  Bank(vector<long long> &balance)
  {
    det = balance;
    n = balance.size();
  }

  bool transfer(int account1, int account2, long long money)
  {
    if ((account1 >= 1 and account1 <= n) and (account2 >= 1 and account2 <= n))
    {
      if (det[account1 - 1] >= money)
      {
        det[account1 - 1] = det[account1 - 1] - money;
        det[account2 - 1] += money;
        return true;
      }
      else
        return false;
    }
    return false;
  }

  bool deposit(int account, long long money)
  {
    if (account >= 1 and account <= n)
    {
      det[account - 1] += money;
      return true;
    }
    return false;
  }

  bool withdraw(int account, long long money)
  {
    if (account >= 1 and account <= n)
    {
      if (det[account - 1] >= money)
      {
        det[account - 1] -= money;
        return true;
      }
    }
    return false;
  }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
int main()
{
}