// https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1

#include <bits/stdc++.h>
using namespace std;

int countPS(string str) {
  int n = str.length();
  vector<vector<int>> t(n, vector<int>(n, 0));

  for (int gap = 0; gap < n; gap++) {
    for (int i=0, j = gap; j < n; i++, j++) {
      if (gap == 0) {
        t[i][j] = 1;
      }
      else if (gap == 1) {
        t[i][j] = str[i] == str[j] ? 3 : 2;
      }
      else {
        if (str[i] == str[j])
          t[i][j] = 1 + t[i][j-1] + t[i+1][j];
        else
          t[i][j] = t[i+1][j] + t[i][j-1] - t[i+1][j-1];
      }
    }
  }
  return t[0][n-1];
}

int main() {
  string str = "aab";
  cout << countPS(str);

  return 0;
}
