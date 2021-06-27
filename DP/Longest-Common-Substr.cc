#include <bits/stdc++.h>
using namespace std;

// Recursive solution
// Time limit exceeded
longestCommonSubstrRecursive(string s1, string s2, int x, int y, int count) {
  if (x == 0 || y == 0) return count;

  if (s1[x-1] == s2[y-1])
    return longestCommonSubstrRecursive(s1, s2, x-1, y-1, count+1);

  int include1 = longestCommonSubstrRecursive(s1, s2, x, y-1, 0);
  int include2 = longestCommonSubstrRecursive(s1, s2, x-1, y, 0);

  return max(count, max(include1, include2));
}

int longestCommonSubStr(string s1, string s2, int x, int y) {
  vector<vector<int>> t(x+1, vector<int>(y+1, 0));
  int ans = 0;

  for (int i=1; i <= x; i++) {
    for (int j = 1; j <= y; j++) {
      if (s1[i-1] == s2[j-1]) {
        t[i][j] = t[i-1][j-1] + 1;
        ans = max(t[i][j], ans);
      }
      else
        t[i][j] = 0;
    }
  }

  return ans;
}

int main() {
  string s1 = "ABCDGH";
  string s2 = "ACDGHR";

  int l1 = s1.length();
  int l2 = s2.length();

  cout << longestCommonSubstrRecursive(s1, s2, l1, l2, 0) << endl;
  cout << longestCommonSubStr(s1, s2, l1, l2);
  
  return 0;
}
