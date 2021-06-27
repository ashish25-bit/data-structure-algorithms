#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>> mat, int n, int k) {
  priority_queue<int> maxHeap;

  for (int i=0; i < n; i++) {
    for (int j=0; j < n; j++) {
      if (maxHeap.size() < k)
        maxHeap.push(mat[i][j]);
          
      else {
        if (maxHeap.top() > mat[i][j]) {
          maxHeap.pop();
          maxHeap.push(mat[i][j]);
        }
      }
    }
  }

  return maxHeap.top();
}

int main() {
  vector<vector<int>> arr = {
    {16, 28, 60, 64},
    {22, 41, 63, 91},
    {27, 50, 87, 93},
    {36, 78, 87, 94}
  };

  int n = arr.size();
  int k = 3;

  cout << kthSmallest(arr, n, 3);
  
  return 0;
}
