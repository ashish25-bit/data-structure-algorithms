// https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1#

#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n) {
  int currSum = arr[0];
  int maxSum  = currSum;

  for (int i=1; i < n; i++) {
    currSum = max(currSum + arr[i], arr[i]);
    maxSum  = max(maxSum, currSum);
  }

  return maxSum;
}

int maximumSumRectangle(vector<vector<int>> M, int R, int C) {
  int maxArea = INT_MIN;

  for (int top=0; top < R; top++) {
    int curr[C];
    memset(curr, 0, sizeof(curr));

    for (int bottom=top; bottom < R; bottom++) {
      for (int i=0; i < C; i++)
        curr[i] = curr[i] + M[bottom][i];

      int sum = maxSubarraySum(curr, C);
      maxArea = max(maxArea, sum);
    }
  }

  return maxArea;
}

int main() {
  vector<vector<int>> mat = {
    {1, 2, -1, -4, -20},
    {-8, -3, 4, 2, 1},
    {3, 8, 10, 1, 3},
    {-4, -1, 1, 7, -6}
  };

  cout << maximumSumRectangle(mat, mat.size(), mat[0].size());

  return 0;
}
