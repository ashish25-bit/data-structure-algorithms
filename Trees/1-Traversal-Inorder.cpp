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

void inorderRecursive(Node* root) {
    if (!root)
        return;
    inorderRecursive(root->left);
    cout << root->data << " ";
    inorderRecursive(root->right);
}

void inorderIterative(Node* root) {
    stack<Node*> s;
    Node* current = root;

    while (current || !s.empty()) {

        while (current) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        cout << current->data << " ";
        s.pop();
        current = current->right;
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

    cout << "Recursive In-Order Traversal: ";
    inorderRecursive(root);
    cout << "\nIterative In-Order Traversal: ";
    inorderIterative(root);

    return 0;
}