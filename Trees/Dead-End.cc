#include <bits/stdc++.h>
using namespace std;

class Node {
  public: 
  int data;
  Node* left;
  Node* right;
  Node* next;

  Node(int val) {
    data  = val;
    left  = NULL;
    right = NULL;
  }
};

// insertion BST
Node* insert(Node* root, int val) {
  if (!root) 
    return new Node(val);

  if (val > root->data)
    root->right = insert(root->right, val);
  
  else if (val < root->data)
    root->left = insert(root->left, val);

  return root;
}

bool isDeadEnd(Node *root) {
  unordered_set<int> hashSet;
  queue<Node *> q;

  q.push(root);

  while (!q.empty()) {
    Node *curr = q.front();
    q.pop();

    int data = curr->data;
    hashSet.insert(data);

    if (
      data == 1 && hashSet.find(2) != hashSet.end() || 
      (
        hashSet.find(data - 1) != hashSet.end() &&
        hashSet.find(data + 1) != hashSet.end()
      )
    ) return true;

    if (curr->left)
      q.push(curr->left);

    if (curr->right)
      q.push(curr->right);
  }

  return false;
}

int main() {
  vector<int> arr = {8, 7, 10, 9, 13, 2};
  Node* root = NULL;
  int N = arr.size();

  for (int i=0; i < N ; i++) root = insert(root, arr[i]);

  cout << isDeadEnd(root);

  return 0;
}
