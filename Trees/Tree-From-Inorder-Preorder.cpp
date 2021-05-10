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

int getIndex(vector<int> arr, int x) {
  for (int i=0; i<arr.size(); i++) {
    if (arr[i] == x) return i;
  }
  return -1;
}

Node* buildTree(int start, int end, vector<int> preOrder, vector<int> inOrder) {
  if (start > end) return NULL;

  static int rootIndex = 0;
  
  Node* root = new Node(preOrder[rootIndex++]);
  if (start == end) return root;

  int inIndex = getIndex(inOrder, root->data);

  root->left = buildTree(start, inIndex - 1, preOrder, inOrder);
  root->right = buildTree(inIndex + 1, end, preOrder, inOrder);

  return root;
}

void inOrder(Node* root) {
  if (!root)
      return;
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

int main() {
  vector<int> preorder = {1, 2, 3, 4, 5};
  vector<int> inorder  = {2, 1, 4, 3, 5};

  Node* root = buildTree(0, preorder.size() - 1, preorder, inorder);
  inOrder(root);

  return 0;
}
