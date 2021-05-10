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

Node* buildTree(int start, int end, vector<int> postOrder, vector<int> inOrder) {
  if (start > end) return NULL;

  static int rootIndex = postOrder.size() - 1;
  
  Node* root = new Node(postOrder[rootIndex--]);
  if (start == end) return root;

  int inIndex = getIndex(inOrder, root->data);

  root->right = buildTree(inIndex + 1, end, postOrder, inOrder);
  root->left = buildTree(start, inIndex - 1, postOrder, inOrder);

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
  vector<int> postOrder = {4, 5, 2, 3, 1};
  vector<int> inorder   = {4, 2, 5, 1, 3};

  Node* root = buildTree(0, postOrder.size() - 1, postOrder, inorder);
  inOrder(root);

  return 0;
}
