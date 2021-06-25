#include <bits/stdc++.h>
using namespace std;

void rotateNumbers(vector<vector<int>> &arr) {
  int dir  = 0;
  int rows = arr.size();
  int cols = arr[0].size();

  int top    = 0;
  int bottom = rows - 1;
  int left   = 0;
  int right  = cols - 1;

  int currElem;
  pair<int, int> coordinate;

  while (top <= bottom && left <= right) {
    // top row from left to right
    if (dir == 0) {

      coordinate.first  = top;
      coordinate.second = left;

      currElem = -1;

      for (int i=left; i <= right; i++) {
        int temp = arr[top][i];
        if (currElem != -1) {
          swap(currElem, arr[top][i]);
        }
        currElem = temp;
      }
      top++;
    }

    // right column from top to bottom
    if (dir == 1) {
      for (int i=top; i <= bottom; i++) {
        int temp = arr[i][right];
        swap(currElem, arr[i][right]);
        currElem = temp;
      }
      right--;
    }

    // bottom row from right to left
    if (dir == 2) {
      for (int i=right; i >= left; i--) {
        int temp = arr[bottom][i];
        swap(currElem, arr[bottom][i]);
        currElem = temp;
      }
      bottom--;
    }

    // left column from bottom to top
    if (dir == 3) {
      for (int i=bottom; i >= top; i--) {
        int temp = arr[i][left];
        swap(currElem, arr[i][left]);
        currElem = temp;
      }
      left++;

      arr[coordinate.first][coordinate.second] = currElem;
    }
    dir = (dir + 1) % 4;
  }

  arr[coordinate.first][coordinate.second] = currElem;
}

int main() {
  vector<vector<int>> arr = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16},
  };
  
  rotateNumbers(arr);

  for (vector<int> row: arr) {
    for (int x: row)
      cout << x << " ";
    cout << endl;
  }

  return 0;
}
