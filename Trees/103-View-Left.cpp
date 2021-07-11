// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

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

vector<int> leftView(Node *root) {
    vector<int> res;
    
    if (!root)
        return res;
    
    queue< pair<Node *, int>> level;
    unordered_set <int> hashSet;
   
    level.push(std::make_pair(root, 0));
   
    while (!level.empty()) {
        pair<Node *, int> pairNode = level.front();
        level.pop();
       
        Node *node = pairNode.first; // current node
        int l = pairNode.second; // current node level
       
        if (node->left) 
            level.push(std::make_pair(node->left, l+1));
            
        if (node->right) 
            level.push(std::make_pair(node->right, l+1));
            
        if (hashSet.find(l) == hashSet.end()) {
            if (node) {
                res.push_back(node->data);
                hashSet.insert(l);
            }
        }
    }
   
    return res;
}

int main() {
  vector<string> nodes = {"10", "4", "7", "3", "2", "6", "N"};
  Node* root = buildTree(nodes);
  for (int x: leftView(root))
    cout << x << " ";
  return 0;
}
