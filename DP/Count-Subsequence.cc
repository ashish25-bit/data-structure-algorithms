// https://practice.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1/

#include <bits/stdc++.h>
using namespace std;

/**
 * nth index for s1
 * mth index for s2
 *
 * if characters at index n and m are NOT equal then decrease the n and continue to look for mth character.
 *
 * if characters at index n and m are equal we have 2 choices:
  * decrease n and continue to search for mth index.
  * or
  * decrease n and search for (m-1)th character i.e. decrease both.
 */
// int countWays(string s1, string s2, int n, int m) {
//   if (m == 0) return 1;
//   if (n == 0) return 0;

//   if (s1[n-1] != s2[m-1])
//     return countWays(s1, s2, n-1, m);

//   return countWays(s1, s2, n-1, m-1) + countWays(s1, s2, n-1, m);
// }

int countWays(string S1, string S2) {
  int n = S1.length();
  int m = S2.length();

  if (n < m) return 0;
  if (n == m && S1 == S2) return 1;
  if (n == m && S1 != S2) return 0;

  int t[n+1][m+1];

  for (int i=0; i<= n; i++) {
    for (int j=0; j<= m; j++) {
      if (j == 0)
        t[i][j] = 1;
      else if (i == 0)
        t[i][j] = 0;
      else if (S1[i-1] != S2[j-1])
        t[i][j] = t[i-1][j];
      else
        t[i][j] = t[i-1][j-1] + t[i-1][j];
    }
  }
  return t[n][m];
}

int main() {
  string S1 = "geeksforgeeks";
  string S2 = "gks";

  cout << countWays(S1, S2);
  return 0;
}
