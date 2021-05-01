#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {        
  int p1 = 0;
  int p2 = 0;
  unordered_map<char, int> hashMap;
  int ans = 0;
  
  while (p2 < s.length() && p1 < s.length()) {
    if (hashMap.find(s[p2]) == hashMap.end()) {
      hashMap[s[p2]] = p2;
      p2++;
      continue;
    }
    
    if (hashMap.find(s[p2]) != hashMap.end()) {
      if (hashMap[s[p2]] < p1 || hashMap[s[p2]] > p2) {
        hashMap[s[p2]] = p2;
        p2++;
        continue;
      }
      ans = max(ans, p2 - p1);
      p1 = hashMap[s[p2]] + 1;
      hashMap.erase(s[p2]);
    }
  }
  
  ans = max(ans, p2 - p1);
  return ans;
}

int main() {
  // string str = "abcabcbb";
  // string str = "bbbb";
  // string str = "advdaf";
  string str = "";
  
  cout << lengthOfLongestSubstring(str);

  return 0;
}
