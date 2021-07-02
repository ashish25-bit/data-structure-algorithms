// https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1

#include <bits/stdc++.h>
using namespace std;

int countTriplets(vector<int> arr, int n, int sum) {
  sort(arr.begin(), arr.end());
  int ans = 0;
  
  for (int i=0; i < n-2; i++) {
  int j = i + 1;
  int k = n-1;

    while (j < k) {
      if (arr[i] + arr[j] + arr[k] >= sum)
        k--;

      else {
        ans = ans + (k - j);
        j++;
      }
    }
  }
  return ans;
}

int main() {
  vector<int> arr = {5, 1, 3, 4, 7};
  int x = 12;

  cout << countTriplets(arr, arr.size(), x);  
  return 0;
}
