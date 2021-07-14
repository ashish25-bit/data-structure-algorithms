// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

#include<bits/stdc++.h>
using namespace std;

typedef unordered_map<char, int> CHAR_MAP;
typedef queue<char> Q;

Q changeQueue(Q q, CHAR_MAP hashMap) {

  while (!q.empty() && hashMap[q.front()] != 1) q.pop();

  return q;
}

string FirstNonRepeating(string A) {
  A = A + '\0';
  CHAR_MAP hashMap;
  Q q;
  int pos = 0;

  hashMap[A[pos]] = 1;
  q.push(A[pos]);
  pos++;

  while (A[pos] != '\0') {
    char curr = A[pos];
    if (!q.empty()) {
      char front = q.front();

      if (hashMap.find(curr) == hashMap.end()) {
        q.push(curr);
        hashMap[curr] = 1;
      }
      else hashMap[curr]++;

      if (hashMap[front] != 1) {
        q = changeQueue(q, hashMap);
        if (q.empty()) A[pos] = '#';
        else A[pos] = q.front();
      }
      else A[pos] = front;
    }
    else {
      if (hashMap.find(curr) == hashMap.end()) {
        q.push(curr);
        hashMap[curr] = 1;
      }
      else {
        hashMap[curr]++;
        A[pos] = '#';
      }
    }
    pos++;
  }

  return A;
}

int main() {
  string str = "aabbcdebcf";
  cout << "Before: " << str << endl;
  string res = FirstNonRepeating(str);
  cout << "After:  " << res;

  return 0;
}

// aabbcdebcf: a#b#ccccdd
// abab: aab#
// aabbbcdeef: a#b##ccccc
// aabb: a#b#