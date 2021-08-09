// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1

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

int getInt(string ch) {
  int x;
  stringstream geeks(ch);
  geeks >> x;

  return x;
}

// level order insertion
Node* buildTree(vector<string> nodes) {
  queue<Node*> q;
  int n = nodes.size();

  int pos = 1;
  Node* root = new Node(getInt(nodes[0]));

  q.push(root);

  while (!q.empty() && pos < n) {
    Node* temp = q.front();
    q.pop();

    string leftChar = nodes[pos++];
    string rightChar = "#";

    if (pos < n)
      rightChar = nodes[pos++];

    if (leftChar != "N") {
      temp->left = new Node(getInt(leftChar));
      q.push(temp->left);
    }

    if (rightChar != "N" && rightChar != "#") {
      temp->right = new Node(getInt(rightChar));
      q.push(temp->right);
    }
  }

  return root;
}

void flattenUtil(Node* curr, Node* &head, Node* &prev) {
  if (!curr) return;

  flattenUtil(curr->left, head, prev);
  if (!head) {
    head = curr;
    prev = head;
  }
  else {
    prev->right = curr;
    curr->left  = prev;
    prev = curr;
  }
  flattenUtil(curr->right, head, prev);
}

Node* bToDLL(Node* root) {
  Node* head = NULL;
  Node* prev = NULL;

  flattenUtil(root, head, prev);
  return head;
}

void print(Node* root) {
  Node* prev = NULL;

  while (root) {
    prev = root;
    cout << root->data << " ";
    root = root->right;
  }
  cout << endl;
  while (prev) {
    cout << prev->data << " ";
    prev = prev->left;
  }
}

int main() {
  vector<string> nodes = {"10", "20", "30", "40", "60"};
  Node* root = buildTree(nodes);

  Node* newRoot = bToDLL(root);
  print(newRoot);

  return 0;
}
