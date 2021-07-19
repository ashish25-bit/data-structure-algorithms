// https://practice.geeksforgeeks.org/problems/print-anagrams-together/1

#include <bits/stdc++.h>
using namespace std;

/**
 * for each string, sort it and add make a add (sorted_string: {original}) to the hashMap.
 */

vector<vector<string>> Anagrams(vector<string>& string_list)  {
  vector<vector<string>> res;
  unordered_map<string, vector<string>> hashMap;

  for (string str: string_list) {
    string curr = str;
    sort(curr.begin(), curr.end());
    hashMap[curr].push_back(str);
  }

  for (auto it: hashMap) {
    res.push_back(it.second);
  }
  return res;
}

int main() {
  vector<string> str = {"act", "god", "cat", "dog", "tac"};
  vector<vector<string>> res = Anagrams(str);

  for (auto arr: res) {
    for (string x: arr) cout << x << " ";
    cout << endl;
  }
  return 0;
}
