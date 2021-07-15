#include <bits/stdc++.h>
using namespace std;

bool zeroSubarray(vector<int> arr, int n, int &left, int &right) {
  unordered_map<int, int> hashMap;
  int sum = 0;
  int maxArea = 0;

  for (int i=0; i < n; i++) {
    sum = sum + arr[i];

    if (sum == 0) {
      left = 0;
      right = i;
      maxArea = i + 1;
    }
    else if (hashMap.find(sum) == hashMap.end())
      hashMap[sum] = i;
    else {
      int currLen = i - hashMap[sum];
      if (currLen > maxArea) {
        left = hashMap[sum] + 1;
        right = i;
        maxArea = currLen;
      }
    }
  }

  if (maxArea == 0) return false;
  return true;
}

vector<int> sumZeroMatrix(vector<vector<int>> mat, int rows, int cols) {
  int maxArea = 0;
  vector<int> coors = {-1, -1, -1, -1};

  for (int top=0; top < rows; top++) {
    vector<int> curr(cols, 0);
    for (int bottom=top; bottom < rows; bottom++) {
      for (int i=0; i < cols; i++)
        curr[i] = curr[i] + mat[bottom][i];

      int left  = 0;
      int right = 0;
      if (zeroSubarray(curr, cols, left, right)) {
        int area = (bottom - top + 1) * (right - left + 1);
        if (area > maxArea) {
          coors[0] = top;
          coors[1] = bottom;
          coors[2] = left;
          coors[3] = right;
          maxArea = area;
        }
      }
    }
  }

  return coors;
}

int main() {
  vector<vector<int>> mat = {
    {9,  7, 16,  5},
    {1, -6, -7,  3},
    {1,  8,  7,  9},
    {7, -2,  0, 10}
  };

  vector<int> res = sumZeroMatrix(mat, mat.size(), mat[0].size());
  int top    = res[0];
  int bottom = res[1];
  int left   = res[2];
  int right  = res[3];

  for (int i=top; i <= bottom; i++) {
    for (int j=left; j <= right; j++)
      cout << mat[i][j] << " ";
    cout << endl;
  }
  return 0;
}
