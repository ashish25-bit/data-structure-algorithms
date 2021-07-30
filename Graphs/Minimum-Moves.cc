// https://www.hackerrank.com/challenges/castle-on-the-grid/problem

#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int rows, int cols, vector<string> grid) {
  return x >= 0 && y >= 0 &&
         x < rows && y < cols &&
         grid[x][y] == '.';
}

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
  int rows = grid.size();
  int cols = grid[0].size();
  int visited[rows][cols];
  memset(visited, 0, sizeof(visited));

  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};

  queue<vector<int>> q;

  q.push({startX, startY, 0});

  while (!q.empty()) {
    vector<int> curr = q.front();
    q.pop();

    curr[2] = curr[2] + 1;

    for (int i = 0; i < 4; i++) {
      int x = curr[0];
      int y = curr[1];

      while (true) {
        x = x + dx[i];
        y = y + dy[i];

        if (isValid(x, y, rows, cols, grid)) {
          if (x == goalX && y == goalY)
            return curr[2];
          else if (visited[x][y] == 0) {
            visited[x][y] = 1;
            q.push({x, y, curr[2]});
          }
        }
        else
          break;
      }
    }
  }

  return -1;
}

int main() {
  vector<string> maze = {".X.", ".X.", "..."};
  int startX = 0;
  int startY = 0;
  int goalX  = 0;
  int goalY  = 2;

  cout << minimumMoves(maze, startX, startY, goalX, goalY);
  return 0;
}
