#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* right;
    Node* left;

    Node(int val) {
        this->data = val;
        this->right = nullptr;
        this->left = nullptr;
    }
};

vector<int> inputArray(int n) {
    int temp;
    vector<int> arr;
    cout << "Enter " << n << " values for array:\n";
    for (int i=0; i<n; i++) {
        cin >> temp;
        arr.push_back(temp);
   }
   return arr;
}

void postorderRecursive(Node* root) {
    if (!root)
        return;
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    cout << root->data << " ";
}

void postorderIterative(Node* node) {
    stack<Node*> s;
    stack<Node*> s2;
    s.push(node);

    while (!s.empty()) {
        Node* temp = s.top();
        s.pop();

        s2.push(temp);

        if (temp->left)
            s.push(temp->left);

        if (temp->right)
            s.push(temp->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main() {
    int n;

    cout << "Enter the value of n\t";
    cin >> n;

    vector<int> vec = inputArray(n);
    Node* root = nullptr;

    /*
        LEVEL ORDER INSERTION
    */
    int count = 0;
    queue<Node*> level;
    for (int x: vec) {
        Node* newNode = new Node(x);
        level.push(newNode);

        if (root == nullptr) {
            root = newNode;
            continue;
        }

        count++;
        Node* node = level.front();

        if (count == 1)
            node->left = newNode;

        if (count == 2) {
            node->right = newNode;
            count = 0;
            level.pop();
        }
    }

    cout << "Recursive Post-Order Traversal: ";
    postorderRecursive(root);
    cout << "\nIterative Post-Order Traversal: ";
    postorderIterative(root);

    return 0;
}