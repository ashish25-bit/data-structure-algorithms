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

typedef pair<Node*, int> P;

void levelOrder(Node* root) {
  queue<P> q;
  q.push(make_pair(root, 0));

  int currLevel = 0;

  while (!q.empty()) {
    P p = q.front();
    q.pop();

    if (p.first->left)
      q.push(make_pair(p.first->left, p.second + 1));
    
    if (p.first->right)
      q.push(make_pair(p.first->right, p.second + 1));

    if (currLevel != p.second) {
      currLevel = p.second;
      cout << endl;
    } 
    cout << p.first->data << "(" << p.second << ") ";
  }
}

void leafNodes(Node* root, vector<int> &v) {
  if (!root) return;

  if (!root->left && !root->right) {
    v.push_back(root->data);
    return;
  }

  leafNodes(root->left, v);
  leafNodes(root->right, v);
}

vector<int> leafNodes(Node* root) {
  vector<int> v;
  leafNodes(root, v);
  return v;
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6};
  Node* root = new Node(arr[0]);
  
  queue<Node*> q;
  q.push(root);
  int pos = 1;

  while (pos < arr.size()) {
    Node* curr = q.front();
    Node* newNode = new Node(arr[pos]);

    if (!curr->left)
      curr->left = newNode;

    else if (!curr->right)
      curr->right = newNode;

    if (curr->left && curr->right)
      q.pop();

    q.push(newNode);
    pos++;
  }

  levelOrder(root);
  vector<int> res = leafNodes(root);

  cout << endl << "Leaf Nodes: ";
  for (int x: res) cout << x << " ";
  
  return 0;
}
