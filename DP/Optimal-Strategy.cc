// https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1

#include <bits/stdc++.h>
using namespace std;

/**
 * concept of minimax is used here
 * if user1 choose start element then user2 will have to choose from index [start+1,end]
  * user2 will try to maximize his profit which will be minimum for us
  * so if user2 choose start index we will have to choose from [start+2, end]
  * else if user2 choose end index we will have to choose from [start+1, end-1]
 * similar will be the case when user1 chooses end index.
 */


// bottom up recursive
// int maximumAmount(vector<int> arr, int start, int end) {
//   if (start == end - 1)
//     return max(arr[start], arr[end]);

//   int includeStart = arr[start] + min(maximumAmount(arr, start + 2, end), maximumAmount(arr, start+1, end-1));
//   int includeEnd   = arr[end]   + min(maximumAmount(arr, start, end - 2), maximumAmount(arr, start+1, end-1));

//   return max(includeStart, includeEnd);
// }

// int maximumAmount(vector<int> arr, int n) {
//   return maximumAmount(arr, 0, n-1);
// }

// top down

int maximumAmount(vector<int> arr, int n) {
  vector<vector<int>> t(n, vector<int>(n, 0));

  for (int gap=0; gap < n; gap++) {
    for (int i=0, j = gap; j < n; i++, j++) {
      if (gap == 0)
        t[i][j] = arr[i];
      else if (gap == 1)
        t[i][j] = max(arr[i], arr[j]);
      else {
        int includeStart = arr[i] + min(t[i+2][j], t[i+1][j-1]);
        int includeEnd   = arr[j] + min(t[i][j-2], t[i+1][j-1]);
        t[i][j] = max(includeStart, includeEnd);
      }
    }
  }

  return t[0][n-1];
}

int main() {
  vector<int> arr = {8, 15, 3, 7};
  cout << maximumAmount(arr, arr.size());
  return 0;
}
