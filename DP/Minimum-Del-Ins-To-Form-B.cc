// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1/

#include <bits/stdc++.h>
using namespace std;

auto minOperations(string str1, string str2) {
  int n = str1.length();
  int m = str2.length();

  int t[m+1][n+1];

  for (int i=0; i <= m; i++) {
    for (int j=0; j <= n; j++) {
      if (i == 0 || j == 0) t[i][j] = 0;
      else if (str2[i-1] == str1[j-1])
        t[i][j] = 1 + t[i-1][j-1];
      else
        t[i][j] = max(t[i-1][j], t[i][j-1]);
    }
  }

  string res = "";
  int row = m;
  int col = n;

  while (row > 0 && col > 0) {
    if (str2[row-1] == str1[col-1]) {
      res = str1[col-1] + res;
      row = row - 1;
      col = col - 1;
    }
    else {
      if (t[row-1][col] >= t[row][col-1])
        row = row - 1;
      else
        col = col - 1;
    }
  }

  int deletions  = m - res.length();
  int insertions = 0;

  int index1 = 0;
  int index2 = 0;

  while (index1 < n && index2 < res.length()) {
    if (str1[index1] == res[index2]) {
      index1++;
      index2++;
    }
    else {
      insertions++;
      index1++;
    }
  }

  if (index2 == res.length() && index1 != n)
    insertions = insertions + n - index1;

  return deletions + insertions;
}

int main() {
  // string str1 = "leetcode";
  // string str2 = "etco";

  string str1 = "geeksforgeeks";
  string str2 = "geeks";

  // string str1 = "heap";
  // string str2 = "pea";

  cout << minOperations(str1, str2);

  return 0;
}
