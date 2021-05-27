#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
  int data;
  Node* left;
  Node* right;
  Node* next;

  Node(int val) {
    data = val;
    left = NULL;
    right = NULL;
    next = NULL;
  }
};

typedef pair<Node*, int> P;

int getInt(string ch) {
  stringstream geeks(ch);
  int x;

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

void populateNext(Node* p) {
  stack<Node*> st;
  Node* curr = p;
  Node* prev = NULL;

  while (curr || !st.empty()) {
    while (curr) {
      st.push(curr);
      curr = curr->left;
    }
    
    if (prev)
        prev->next = !st.empty() ? st.top() : NULL;
    
    if (st.empty()) break;
    
    curr = st.top();
    st.pop();
    prev = curr;
    curr = curr->right;
  }
}

void inOrder(Node* root) {
  if (!root) return;

  inOrder(root->left);
  cout << root->data << "->" << (root->next ? root->next->data : -1) << "\t";
  inOrder(root->right);

}

int main() {
  vector<string> nodes = {"1", "2", "3", "4", "5", "6", "7"};
  Node* root = buildTree(nodes);

  populateNext(root);
  inOrder(root);

  return 0;
}
