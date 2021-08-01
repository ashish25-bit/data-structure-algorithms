// https://practice.geeksforgeeks.org/problems/unique-bsts-1587115621/1/

#include <bits/stdc++.h>
using namespace std;

/**
 * Catalan number
 */
long numTrees(int N) {
  int mod = 1000000007;
  if (N == 0)
    return 1;
  if (N == 1 || N == 2)
    return N;

  long t[N+1];
  t[0] = 1;
  t[1] = 1;
  t[2] = 2;

  for (int i = 3; i <= N; i++) {
    t[i] = 0;
    int low = 0;
    int high = i - 1;

    while (low <= i - 1) {
      t[i] = (t[i] + (t[low] * t[high]) % mod) % mod;
      low++;
      high--;
    }
  }
  return t[N] % mod;
}

int main() {
  cout << numTrees(4);
  return 0;
}
