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

Node* flatten(Node* root) {
  stack<Node*> st;
  Node* curr = root;
  Node* head = NULL;
  Node* prev = NULL;

  while (curr || !st.empty()) {
    while (curr) {
      st.push(curr);
      curr = curr->left;
    }

    if (prev)
      prev->right = st.empty() ? NULL : st.top();

    if (st.empty()) break;

    curr = st.top();
    st.pop();

    if (!head)
      head = curr;
    
    prev = curr;
    curr = curr->right;
  }

  return head;
}

int main() {
  vector<int> arr = {10, 6, 15, 4, 7, 13, 17, 2, 3, 16, 18};
  Node* root = NULL;
  int N = arr.size();

  for (int i=0; i < N ; i++) root = insert(root, arr[i]);

  root = flatten(root);
  
  while (root) {
    cout << root->data << " ";
    root = root->right;
  }

  return 0;
}
