#include <bits/stdc++.h>
using namespace std;

typedef pair<char, int> P;

struct comparator {
  bool operator() (P p1, P p2) {
    if (p1.second == p2.second)
      return p1.first > p2.first;
    return p1.second < p2.second;
  }
};

string reorganizeString(string S) {
  priority_queue<P, vector<P>, comparator> maxHeap;
  unordered_map<char, int> hashMap;
  string res = "";

  for (int i=0; i < S.length(); i++) 
    hashMap[S[i]]++;

  for (auto it: hashMap) {
    P p;
    p.first = it.first;
    p.second = it.second;

    maxHeap.push(p);
  }

  P prev;
  prev.first = '#';
  prev.second = -1;

  while (!maxHeap.empty()) {
    P top = maxHeap.top();
    int len = res.length();

    maxHeap.pop();
    if (prev.second != -1)
      maxHeap.push(prev);

    if (len != 0 && top.first == res[len-1])
      return "";

    res = res + top.first;
    top.second = top.second - 1;

    if (top.second > 0)
      prev = top;
    else {
      prev.first = '#';
      prev.second = -1;
    }
  }

  if (prev.second != -1) {
    int len = res.length();
    if (len != 0 && prev.first == res[len-1])
      return "";
  }

  return res;
}

int main() {
  vector<string> arr = {
    "baaba",
    "aaabbb",
    "aab",
    "aaab",
    "abcda"
  };

  for (string str: arr)
    cout << str << ": " << reorganizeString(str) << endl;
  
  return 0;
}
