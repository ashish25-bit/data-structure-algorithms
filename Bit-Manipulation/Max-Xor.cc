#include <bits/stdc++.h>
using namespace std;

int maxXor(int lo, int hi, int k) {
  vector<int> arr;

  for (int i=lo; i <= hi; i++) arr.push_back(i);

  int maxx = 0, mask = 0;
  set<int> se;
  int n = arr.size();

  for (int i = 30; i >= 0; i--) {
    mask |= (1 << i);

    for (int i = 0; i < n; ++i)
      se.insert(arr[i] & mask);

    int newMaxx = maxx | (1 << i);

    for (int prefix : se) {
      int temp = newMaxx ^ prefix;
      if (se.count(temp)) {
        if (newMaxx <= k) {
          maxx = newMaxx;
          break;
        }
      }
    }

    se.clear();
  }

  return maxx;
}

int main() {
  // int lo = 2;
  // int hi = 4;
  // int k  = 8;
  int lo = 3;
  int hi = 5;
  int k  = 6;

  cout << maxXor(lo, hi, k);
  
  return 0;
}
