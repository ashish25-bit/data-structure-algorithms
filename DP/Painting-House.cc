/**
 * Given m colors and n houses
 * the cost of paint ith house with jth color is given in prices[i][j]
 * Paint the houses such that the no two houses have same color and cost of painting house is minimum
 */

#include <bits/stdc++.h>
using namespace std;

pair<int, int> findMinIndex(int arr[], int n) {
  int minIndex = -1;
  int secondMinIndex = -1;

  for (int i=0; i < n; i++) {
    if (minIndex == -1) {
      minIndex = 0;
    }
    else {
      if (arr[i] <= arr[minIndex]) {
        secondMinIndex = minIndex;
        minIndex = i;
      }
      else if (secondMinIndex == -1) {
        secondMinIndex = i;
      }
      else if (arr[i] <= arr[secondMinIndex]) {
        secondMinIndex = i;
      }
    }
  }

  return {minIndex, secondMinIndex};
}

void countSum(int n, vector<vector<int>> prices, int colors) {
  int t[n][colors];
  memset(t, 0, sizeof(t));
  pair<int, int> minIndex;

  for (int i=0; i < n; i++) {
    for (int j=0; j < colors; j++) {
      int curr = prices[i][j];
      if (i == 0) {
        t[i][j] = curr;
      }
      else {
        if (j == minIndex.first) {
          t[i][j] = curr + t[i-1][minIndex.second];
        }
        else {
          t[i][j] = curr + t[i-1][minIndex.first];
        }
      }
    }
    minIndex = findMinIndex(t[i], colors);
  }

  int res = INT_MAX;
  for (int i=0; i < n; i++) {
    for (int j=0; j < colors; j++)
      cout << t[i][j] << " ";
    cout << endl;
  }
}

int main() {
  vector<vector<int>> prices = {
    {1, 5, 7, 2, 1, 4},
    {5, 8, 4, 3, 6, 1},
    {3, 2, 9, 7, 2, 3},
    {1, 2, 4, 9, 1, 7},
  };

  countSum(prices.size(), prices. prices[0].size());
  return 0;
}
