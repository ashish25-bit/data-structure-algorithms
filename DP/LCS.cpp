#include <bits/stdc++.h>
using namespace std;

// TIME LIMIT EXCEEDED IN GFG
// string getKey(int a, int b) {
//   return to_string(a) + "-" + to_string(b);
// }

// int LCS(string str1, string str2, int l1, int l2, unordered_map<string, int> &hashMap) {
//   if (l1 == 0 || l2 == 0) return 0;

//   string key = getKey(l1, l2);

//   if (hashMap.find(key) != hashMap.end())
//     return hashMap[key];

//   if (str1[l1-1] == str2[l2-1])
//     return hashMap[key] = 1 + LCS(str1, str2, l1-1, l2-1, hashMap);

//   int decreaseLen1 = LCS(str1, str2, l1-1, l2, hashMap);
//   int decreaseLen2 = LCS(str1, str2, l1, l2-1, hashMap);
//   return hashMap[key] = max(decreaseLen1, decreaseLen2);
// }

int lcs(int x, int y, string s1, string s2) {
  vector<vector<int>> t(x+1, vector<int>(y+1, 0));
  
  for (int i=1; i <= x; i++) {
    for (int j=1; j <= y; j++) {
      if (s1[i-1] == s2[j-1]) 
        t[i][j] = 1 + t[i-1][j-1];
      else 
        t[i][j] = max(t[i][j-1], t[i-1][j]);
    }
  }
  
  return t[x][y];
}

int main() {
  string str1 = "ABCDGH";
  string str2 = "AEDFHR";

  int l1 = str1.length();
  int l2 = str2.length();

  cout << lcs(l1, l2, str1, str2);
  
  return 0;
}
