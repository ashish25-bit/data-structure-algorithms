#include<bits/stdc++.h>
using namespace std;

/**
 * Taking the ith element and putting it at the first position i.e at index = 0
 * if at index=0 the effect of that number is nullified
 * there removing this from the curr val
 * and remaining number should be increase sum - arr[i] is added to the curr_val
 */
int max_sum(vector<int> A, int N) {
  int curr_val = 0;
  int sum = 0;

  for (int i=0; i<N; i++) {
    curr_val = curr_val + A[i] * i;
    sum += A[i];
  }

  int res = curr_val;

  for (int i=N-1; i >= 1; i--) {
    int temp = curr_val - (A[i] * (N-1)) + (sum - A[i]);
    
    res = max(res, temp);
    curr_val = temp;
  }

  return res;
}

int main() {
  vector<int> arr = {8, 3, 1, 2};
  cout << max_sum(arr, arr.size());
  
  return 0;
}
