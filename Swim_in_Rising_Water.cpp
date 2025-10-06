#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  bool check(vector<vector<int>> &grid, int mid)
  {
    int n = grid.size();
    queue<pair<int, int>> qu;

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    if (grid[0][0] > mid)
      return false;
    qu.push({0, 0});
    visited[0][0] = true;
    while (!qu.empty())
    {
      auto [r, c] = qu.front();
      qu.pop();
      if (r == n - 1 && c == n - 1)
        return true;
      for (int i = 0; i < 4; i++)
      {
        int newRow = r + dir[i][0];
        int newCol = c + dir[i][1];

        if (newRow >= 0 and newCol >= 0 and newRow < grid.size() and
            newCol < grid.size() and !visited[newRow][newCol] and
            grid[newRow][newCol] <= mid)
        {
          visited[newRow][newCol] = true;
          qu.push({newRow, newCol});
        }
      }
    }
    return false;
  }

  int swimInWater(vector<vector<int>> &grid)
  {
    int first = grid[0][0];
    int last = 0;
    int n = grid.size();
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        last = max(last, grid[i][j]);
      }
    }
    int ans = 0;
    while (first <= last)
    {
      int mid = (first + last) / 2;

      if (check(grid, mid))
      {
        ans = mid;
        last = mid - 1;
      }
      else
      {
        first = mid + 1;
      }
    }
    return ans;
  }
};

int main()
{
}