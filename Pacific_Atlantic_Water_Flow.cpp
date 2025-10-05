#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int row;
  int col;
  vector<vector<int>> height;
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
  {

    queue<pair<int, int>> p, a;
    height = heights;
    row = height.size();
    col = height[0].size();

    for (int i = 0; i < row; i++)
    {
      p.push({i, 0});
      a.push({i, col - 1});
    }
    for (int i = 1; i < col; i++)
    {
      p.push({0, i});
    }
    for (int i = 0; i < col; i++)
    {
      a.push({row - 1, i});
    }

    vector<vector<bool>> po = bfs(p);
    vector<vector<bool>> ao = bfs(a);
    vector<vector<int>> ans;
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
      {
        if (po[i][j] && ao[i][j])
        {
          ans.push_back({i, j});
        }
      }
    }

    return ans;
  }
  vector<vector<bool>> bfs(queue<pair<int, int>> qu)
  {
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    while (!qu.empty())
    {
      auto [i, j] = qu.front();
      qu.pop();
      if (visited[i][j])
        continue;
      visited[i][j] = true;

      for (int d = 0; d < 4; d++)
      {
        int newRow = i + dir[d][0];
        int newCol = j + dir[d][1];

        if (newRow < 0 || newCol < 0 || newRow >= row || newCol >= col)
          continue;
        if (visited[newRow][newCol])
          continue;
        if (height[newRow][newCol] < height[i][j])
          continue;

        qu.push({newRow, newCol});
      }
    }
    return visited;
  }
};

int main()
{
}