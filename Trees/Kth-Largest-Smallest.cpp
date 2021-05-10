#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = NULL;
    right = NULL;
  }
};

Node* insert(Node* root, int value) {
  if (!root) return new Node(value);

  if (value > root->data) 
    root->right = insert(root->right, value);
  else (value < root->data)
    root->left = insert(root->left, value);
  return root;
}

// ##########################
void kthLargest(Node* root, int k, int &c, int &ans) {
  if (!root || c > k) return;

  kthLargest(root->right, k, c, ans);
  c = c+1;

  if (c == k) {
    ans = root->data;
    return;
  }

  kthLargest(root->left, k, c, ans);
}

int kthLargest(Node* root, int k) {
  int ans = -1;
  int c = 0;

  kthLargest(root, k, c, ans);
  
  return ans;
}
// ##########################

// ##########################
void kthSmallest(Node* root, int k, int &c, int &ans) {
  if (!root || c > k) return;

  kthSmallest(root->left, k, c, ans);
  c = c+1;

  if (c == k) {
    ans = root->data;
    return;
  }

  kthSmallest(root->right, k, c, ans);
}

int kthSmallest(Node* root, int k) {
  int ans = -1;
  int c = 0;

  kthSmallest(root, k, c, ans);
  
  return ans;
}
// ##########################

int main() {
  vector<int> arr = {10, 8, 15, 13, 18};
  Node* root = insert(NULL, arr[0]);

  for (int i=1; i<arr.size(); i++) 
    insert(root, arr[i]);

  for (int i=1; i <= arr.size(); i++) 
    cout << i << "th largest: " << kthLargest(root, i) << endl;

  cout << endl;

  for (int i=1; i <= arr.size(); i++) 
    cout << i << "th smallest: " <<
     kthSmallest(root, i) << endl;

  return 0;
}
