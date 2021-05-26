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

void levelOrder(Node* root) {
  queue<Node*> q;
  q.push(root);

  while (!q.empty()) {
    Node* node = q.front();
    q.pop();

    if (node->left)
      q.push(node->left);

    if (node->right)
      q.push(node->right);

    cout << node->data << " ";
  }
}

Node* insert(Node* root, int val) {
  if (!root) 
    return new Node(val);

  if (val > root->data)
    root->right = insert(root->right, val);
  
  else if (val < root->data)
    root->left = insert(root->left, val);

  return root;
}

Node* findMax(Node* root, int &data) {
  if (!root->right) {
    data = root->data;
    Node* temp = root->left;
    delete(root);
    return temp;
  }

  root->right = findMax(root->right, data);
  return root;
}

Node* deleteNode(Node* root, int key) {
  if (!root) return NULL;

  if (root->data > key)
    root->left = deleteNode(root->left, key);
  
  else if (root->data < key)
    root->right = deleteNode(root->right, key);

  else {
    if (!root->left && !root->right) {
      delete(root);
      return NULL;
    }

    else if (root->right && !root->left) {
      Node* temp = root;
      root = root->right;
      temp->right = NULL;
      delete(temp);
    }

    else {
      int data;
      root->left = findMax(root->left, data);
      root->data = data;
    }

  }
  
  return root;
}

int main() {
  // vector<int> arr = {10, 5, 6, 15, 11, 3, 18, 17, 20, 15};
  vector<int> arr = {15, 8, 18, 4, 10, 17, 20, 3, 5, 9, 13, 7, 6, 8};
  Node* root = NULL;
  int N = arr.size();

  for (int i=0; i < N - 1; i++) root = insert(root, arr[i]);

  cout << "Before Deleting;\n";
  levelOrder(root);

  root = deleteNode(root, arr[N-1]);

  cout << "\n\nAfter Deleting;\n";
  levelOrder(root);

  return 0;
}
