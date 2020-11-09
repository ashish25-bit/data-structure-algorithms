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

vector<int> levelOrder(Node *node) {
    vector<int> res;

    queue<Node*> levelNodes;
    levelNodes.push(node);

    while (!levelNodes.empty()) {
        Node* temp = levelNodes.front();

        res.push_back(temp->data);

        if (temp->left)
            levelNodes.push(temp->left);

        if (temp->right)
            levelNodes.push(temp->right);

        levelNodes.pop();
    }

    return res;
}

int height(Node* node) {
    if (node == NULL)
        return 0;

    int leftSubtree = height(node->left);
    int rightSubtree = height(node->right);

    if (leftSubtree > rightSubtree)
        return (leftSubtree + 1);
    return (rightSubtree + 1);
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

    cout << "Height of a tree: " << height(root);

    return 0;
}
