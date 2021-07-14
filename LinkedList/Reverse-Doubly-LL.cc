// https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
  int data;
  Node* next;
  Node* prev;

  Node(int val) {
    data = val;
    next = NULL;
    prev = NULL;
  } 
};

void printLL(Node* head) {
  while (head) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

Node* getList(vector<int> arr) {
  Node* head = NULL;
  Node* tail = NULL;

  for (int x: arr) {
    Node* newNode = new Node(x);

    if (!head) {
      head = newNode;
      tail = newNode;
    }
    else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
  }
  return head;
}

Node* reverseDLL(Node * head) {
  while (head->next)
    head = head->next;

  Node* curr = head;
  Node* next = head;
  Node* prev = NULL;

  while (curr) {
    next = curr->prev;
    curr->prev = prev;
    curr->next = next;
    prev = curr;
    curr = next;
  }

  return head;
}

int main() {
  vector<int> arr = {1, 2, 3, 4};
  Node* root = getList(arr);

  printLL(root);
  root = reverseDLL(root);
  printLL(root);
  
  return 0;
}
