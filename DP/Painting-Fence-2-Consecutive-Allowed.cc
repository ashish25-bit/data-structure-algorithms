// https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1#

#include <bits/stdc++.h>
using namespace std;

long long countWays(int n, int k) {
  if (n == 1)
    return k;

  const long long mod = 1000000007;
  long long same = 1;
  long long _same = 1;

  for (int i = 2; i <= n; i++) {
    if (i == 2) {
      same = k;
      _same = (k * (k - 1)) % mod;
    }
    else {
      long long temp = _same;
      _same = ((_same + same) % mod * (k - 1)) % mod;
      same = temp;
    }
  }

  return (same + _same) % mod;
}

int main() {
  int n = 2;
  int k = 4;
  cout << countWays(n, k);
  return 0;
}
