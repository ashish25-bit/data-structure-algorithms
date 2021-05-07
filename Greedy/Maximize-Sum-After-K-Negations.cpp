#include <bits/stdc++.h>
using namespace std;

int maximizeSum(vector<int> a, int k) {
  int n = a.size();
  sort(a.begin(), a.end());
  
  int sum = 0;
  int minPositive = a[0];
  int pos = 0;
  
  while (k && a[pos] < 0) {
    a[pos] = -a[pos];
    minPositive = a[pos];
    pos++;
    k--;
  }
  
  for (int i=0; i<n; i++) sum = sum + a[i];
  
  if (k % 2 == 0) return sum;
  
  minPositive = min(a[pos], minPositive);
  
  sum = sum - 2 * minPositive;
  return sum;
}

void printArr(vector<int> arr) {
  for (int x: arr) cout << x << " ";
}

int main() {

  // last element is the value of k
  vector<vector<int>> data = {
    {1, 2, -3, 4, 5,  1},
    {1, 2, -3, 4, 5,  2},
    {5, -2, 5, -4, 5, -12, 5, 5, 5, 20,   5},
    {5, -2, 5, -4, 5, -12, 5, 5, 5, 20,   8}
  };

  for (vector<int> arr: data) {
    int k = arr[arr.size() - 1];
    arr.pop_back();
    cout << "arr: { ";
    printArr(arr);
    cout << "} and k = " << k << endl;

    cout << maximizeSum(arr, k) << "\n\n";
  }
  
  return 0;
}
