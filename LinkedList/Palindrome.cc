#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node(int val) {
    this->data = val;
    this->next = NULL;
  }
};

Node *getList(vector<int> arr) {
  Node *head = NULL;
  Node *tail = NULL;

  for (int x : arr) {
    Node *newNode = new Node(x);

    if (!head) {
      head = newNode;
      tail = newNode;
    }
    else {
      tail->next = newNode;
      tail = newNode;
    }
  }
  return head;
}

Node* reverseLL(Node* head) {
  Node* current = head;
  Node* prev = NULL;
  Node* next = NULL;

  while (current) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

bool palindrome(Node* head) {
  // no node
  if (!head) return false;

  // only one node
  if (head->next == NULL) return true;

  Node* head2 = head;
  Node* fast = head;
  Node* prev = NULL;

  while (fast && fast->next) {
    prev = head2;
    head2 = head2->next;
    fast = fast->next->next;
  }

  prev->next = NULL;
  if (fast && fast->next == NULL)
    head2 = head2->next;

  head2 = reverseLL(head2);

  while (head && head2) {
    if (head->data != head2->data)
      return false;
    
    head = head->next;
    head2 = head2->next;
  }

  if ((head && !head2) || (!head && head2)) return false;

  return true;
}

int main() {
  vector<int> arr = {1, 2, 2, 1};
  Node* root = getList(arr);
  cout << palindrome(root);

  return 0;
}
