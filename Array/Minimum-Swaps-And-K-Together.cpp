// Input : arr[] = {2, 7, 9, 5, 8, 7, 4} and K = 6 
// Output :  2 

// Input : arr[ ] = {2, 1, 5, 6, 3} and K = 3
// Output : 1

// https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1
#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> arr, int k) {
  int count = 0;
  int p1 = 0;
  int p2 = 0;
  int swaps = 0;
  int n = arr.size();

  for (int x: arr) 
    if (x <= k) p2++;
  
  if (p2 == 1 || p2 == 0 || p2 == arr.size()) return 0;

  p2--;

  for (int i=p1; i<=p2; i++)
    if (arr[i] > k) count++;

  swaps = count;
  while (p2 < n) {
    swaps = min(swaps, count);

    p2++;
    if (p2 < n && arr[p2] > k) count++;
    if (arr[p1] > k) count--;
    p1++;
  }

  return swaps;
}

void printArr(vector<int> arr) {
  for (int x: arr) cout << x << " ";
}

int main() {

  // NOTE: THE LAST ELEMENT IN EACH ARRAY IS THE VALUE OF K
  vector<vector<int>> data = {
    {2, 7, 9, 8, 5, 7, 4,    6},
    {2, 7, 9, 5, 8, 7, 4,    6},
    {2, 1, 5, 6, 3,    3},
  };

  // cout << minSwaps(arr, k);
  for (vector<int> arr: data) {
    int k = arr[arr.size() - 1];
    arr.pop_back();
    printArr(arr);
    cout << "and k = " << k << endl;
    cout << minSwaps(arr, k) << "\n\n";
  }
  
  return 0;
}
