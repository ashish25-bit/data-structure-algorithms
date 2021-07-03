// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
  int data;
  Node* next;
  Node* bottom;

  Node(int val) {
    data = val;
    next = NULL;
    bottom = NULL;
  }
};

Node* merge(Node* n1, Node* n2) {
  if (!n1 && !n2) return NULL;

  if (!n1) return n2;
  if (!n2) return n1;

  Node* root;
  if (n1->data < n2->data) {
    root = n1;
    n1 = n1->bottom;
  }
  else {
    root = n2;
    n2 = n2->bottom;
  }
  Node* curr = root;

  while (n1 && n2) {
    if (n1->data <= n2->data) {
      curr->bottom = n1;
      curr = n1;
      n1 = n1->bottom;
    }
    else {
      curr->bottom = n2;
      curr = n2;
      n2 = n2->bottom;
    }
  }

  while (n1) {
    curr->bottom = n1;
    curr = n1;
    n1 = n1->bottom;
  }

  while (n2) {
    curr->bottom = n2;
    curr = n2;
    n2 = n2->bottom;
  }

  root->next = NULL;
  return root;
}

Node* flatten(Node* node) {
  if (!node) return NULL;

  if (!node->next) return node;

  Node* newNode = flatten(node->next);
  newNode = merge(node, newNode);
  return newNode;
}

int main() {
  vector<list<int>> data = {
    {5, 7, 8, 30},
    {10, 20},
    {19, 22, 50},
    {28, 35, 40, 45}
  };

  Node* root = NULL;
  Node* tail = NULL;

  for (list<int> arr: data) {
    Node* newNode = new Node(arr.front());
    arr.pop_front();

    if (!root) {
      root = newNode;
      tail = newNode;
    }
    else {
      tail->next = newNode;
      tail = newNode;
    }

    Node *currNode = newNode;
    for (int x: arr) {
      Node* bottomNode = new Node(x);
      currNode->bottom = bottomNode;
      currNode = bottomNode;
    }
  }
  

  // while (root) {
  //   cout << root->data << ": \n";
  //   Node* bottomNode = root->bottom;

  //   while (bottomNode) {
  //     cout << bottomNode->data << " ";
  //     bottomNode = bottomNode->bottom;
  //   }
  //   cout << endl;
  //   root = root->next;
  // }

  root = flatten(root);
  while (root) {
    cout << root->data << " ";
    root = root->bottom;
  }

  return 0;
}
