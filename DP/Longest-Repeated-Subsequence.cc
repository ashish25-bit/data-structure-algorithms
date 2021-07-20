#include <bits/stdc++.h>
using namespace std;

/**
 * same as LCS
 * but ignore the i == j
 */

int LongestRepeatingSubsequence(string str) {
  int n = str.length();
  vector<vector<int>> t(n+1, vector<int>(n+1, 0));

  for (int i=1; i <= n; i++) {
    for (int j=1; j <= n; j++) {
      if (str[i-1] == str[j-1] && i != j)
        t[i][j] = 1 + t[i-1][j-1];
      else
        t[i][j] = max(t[i-1][j], t[i][j-1]);
    }
  }

  return t[n][n];
}

int main() {
  string str = "axxxy";
  cout << LongestRepeatingSubsequence(str);
  return 0;
}
