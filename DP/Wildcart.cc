// https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1/

#include <bits/stdc++.h>
using namespace std;

/**
 * if both the indexes reached there end then we can return true
 *
 * if the pattern string has reached its end but the input string has not then return false
 *
 * if the input string has reached it end then check whether the reamining character in the pattern string are '*' or not
  * if yes return true else false
 *
 * if the characters at index1 and index2 are equal or char at index2 is a '?' then
  * increment both indexes and move forward.
 *
 * if char at index2 is '*' then we have 3 options
  * match char at index1 and index2 and increment both(ONLY ONCE)
  * else match char at index1 and index2 and increment index1 keeping index2 at *
  * else do not match '*' with any character and move forward(index1, index2+1).
 */

// accepted on gfg but TLE on leetcode.
// int wildCardUtil(string s1, string s2, int n, int m, int index1, int index2, vector<vector<int>> &t) {
//   if (index1 == n && index2 == m) return 1;

//   if (index1 == n) {
//     for (int i=index2; i < m; i++) {
//       if (s2[i] != '*') return 0;
//     }
//     return 1;
//   }

//   if (m == index2 && index1 != n) return 0;

//   if (t[index1][index2] != -1)
//     return t[index1][index2];

//   if (
//     s1[index1] == s2[index2] ||
//     s2[index2] == '?'
//   ) {
//     t[index1][index2] = wildCardUtil(s1, s2, n, m, index1+1, index2+1, t);
//     return t[index1][index2];
//   }

//   if (s2[index2] == '*') {
//     t[index1][index2] = wildCardUtil(s1, s2, n, m, index1+1, index2+1, t);
//     if (t[index1][index2] == 1)
//       return 1;

//     t[index1][index2] = wildCardUtil(s1, s2, n, m, index1+1, index2, t);
//     if (t[index1][index2] == 1)
//       return 1;

//     t[index1][index2] = wildCardUtil(s1, s2, n, m, index1, index2+1, t);
//     return t[index1][index2];
//   }
//   return 0;
// }

// int wildCard(string s1, string s2, int n, int m) {
//   vector<vector<int>> t(n, vector<int>(m, -1));

//   int ans = wildCardUtil(s1, s2, n, m, 0, 0, t);
//   return ans;
// }

// https://leetcode.com/problems/wildcard-matching/
bool wildCard(string s1, string s2) {
  int n = s1.length();
  int m = s2.length();

  bool t[m+1][n+1];

  for (int i=m; i >= 0; i--) {
    for (int j=n; j >= 0; j--) {
      if (i == m && j == n)
        t[i][j] = true;
      else if (i == m)
        t[i][j] = false;
      else if (j == n) {
        if (s2[i] == '*')
          t[i][j] = t[i+1][j];
        else
          t[i][j] = false;
      }
      else if (s1[j] == s2[i] || s2[i] == '?')
        t[i][j] = t[i+1][j+1];
      else if (s2[i] == '*')
        //        match once ||  match more than one char || do not match at all.
        t[i][j] = t[i+1][j+1] || t[i+1][j] || t[i][j+1];
      else
        t[i][j] = false;
    }
  }

  return t[0][0];
}

int main() {
  vector<pair<string, string>> input = {
    {"aa", "a"},
    {"aa", "*"},
    {"cb", "?a"},
    {"adceb", "*a*b"},
    {"acdcb", "a*c?b"},
    {"aa", "***aa***"},
  };

  for (auto it: input) {
    cout << it.first << " " << it.second << ": " << wildCard(it.first, it.second) << endl;
  }

  return 0;
}
