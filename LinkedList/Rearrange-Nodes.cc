// https://practice.geeksforgeeks.org/problems/rearrange-a-linked-list/1

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
  int data;
  Node* next;

  Node(int val) {
    data = val;
    next = NULL;
  }
};

void rearrangeEvenOdd(Node *head) {
  if (!head) return;
  
  // only one node
  if (!head->next) return;
  
  Node* odd  = head;
  Node* even = head->next;
  
  // only 2 nodes
  if (!even->next) return;
  
  Node* evenHead = even;
  
  while (odd && even && even->next) {
    odd->next = even->next;
    odd = even->next;
    
    even->next = odd->next;
    even = odd->next;
    odd->next = evenHead;
  }
}

int main() {
  vector<int> arr = {2, 3};
  Node* root = new Node(1);
  Node* tail = root;

  for (int x: arr) {
    tail->next = new Node(x);
    tail = tail->next;
  }

  rearrangeEvenOdd(root);
  while (root) {
    cout << root->data << " ";
    root = root->next;
  }

  return 0;
}
