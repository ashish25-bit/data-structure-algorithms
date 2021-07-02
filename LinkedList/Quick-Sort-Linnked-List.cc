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

unordered_set<Node*> hashSet;

vector<Node*> partition(Node* start, Node* end) {
  Node* pivot = end;
  Node* prev = NULL;
  Node* curr = start;
  Node* index = start;

  while (curr != end) {
    if (curr->data < pivot->data) {
      prev = index;

      int temp = index->data;
      index->data = curr->data;
      curr->data = temp;

      index = index->next;
    }
    curr = curr->next;
  }

  int temp = pivot->data;
  pivot->data = index->data;
  index->data = temp;

  return {prev, index, index->next};
}

void quickSortUtil(Node* start, Node* end) {
  if (!start || !end || start == end) return;
  if (hashSet.find(start) != hashSet.end()) return;
  if (hashSet.find(end) != hashSet.end()) return;

  vector<Node*> nodes = partition(start, end);
  hashSet.insert(nodes[1]);

  quickSortUtil(start, nodes[0]);
  quickSortUtil(nodes[2], end);
}

Node* quickSortHelper(Node* head) {
  Node* start = head;
  Node* end = head;

  while (end->next) end = end->next;

  quickSortUtil(start, end);
  
  return head;
}

void quickSort(Node** headRef) {
  hashSet.clear();
  Node* data = quickSortHelper(*headRef);
  *headRef = data;
}

int main() {
  vector<int> arr = {1, 9, 3, 8};
  Node* root = NULL;
  Node* tail = NULL;

  for (auto k: arr) {
    if (!root) {
      root = new Node(k);
      tail = root;
    }
    else {
      Node* newNode = new Node(k);
      tail->next = newNode;
      tail = newNode;
    }
  }

  quickSort(&root);
  while (root) {
    cout << root->data << " ";
    root = root->next;
  }

  return 0;
}
