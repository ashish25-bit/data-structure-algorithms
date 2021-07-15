// https://www.geeksforgeeks.org/largest-area-rectangular-sub-matrix-equal-number-1s-0s/

#include <bits/stdc++.h>
using namespace std;

bool equalOneZero(vector<int> arr, int n, int &left, int &right) {
  unordered_map<int, int> hashMap;
  hashMap[0] = -1;

  int curr = 0;
  int maxLen = 0;

  for (int i=0; i < n; i++) {
    curr = curr + arr[i];

    if (curr == 0) {
      left = 0;
      right = i;
      maxLen = right - left + 1;
    }

    else if (hashMap.find(curr) != hashMap.end()) {
      int currLen = i - hashMap[curr];
      if (currLen > maxLen) {
        left = hashMap[curr] + 1;
        right = i;
        maxLen = currLen;
      }
    }

    else hashMap[curr] = i;
  }

  if (maxLen == 0) return false;
  return true;
}

int maxArea(vector<vector<int>> mat, int row, int col) {
  int maxArea = 0;

  for (int top=0; top < row; top++) {
    vector<int> arr(col, 0);
    for (int bottom = top; bottom < row; bottom++) {
      int left  = 0;
      int right = 0;

      for (int i=0; i <col; i++)
        arr[i] = arr[i] + (mat[bottom][i] == 0 ? -1 : 1);

      if (equalOneZero(arr, col, left, right)) {
        int area = (bottom - top + 1) * (right - left + 1);
        maxArea = max(maxArea, area);
      }
    }
  }

  return maxArea;
}

int main() {
  vector<vector<int>> mat = {
    {0, 0, 1, 1},
    {0, 1, 1, 0},
    {1, 1, 1, 0},
    {1, 0, 0, 1}
  };

  cout << maxArea(mat, mat.size(), mat[0].size());

  return 0;
}
