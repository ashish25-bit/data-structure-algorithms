#include <bits/stdc++.h>
using namespace std;

bool check(Node *root) {
  unordered_set<int> hashSet;
  queue<P> q;
  q.push(make_pair(root, 0));
  
  while (!q.empty()) {
    P top = q.front();
    q.pop();
    
    if (top.first->left)
      q.push(make_pair(top.first->left, top.second + 1));
        
    if (top.first->right)
      q.push(make_pair(top.first->right, top.second + 1));
        
    if (!top.first->left && !top.first->right)
      hashSet.insert(top.second);
        
    if (hashSet.size() > 1)
      return false;
  }
  
  return hashSet.size() <= 1;
}

int main() {
  return 0;
}
