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

void printArray(vector<int> arr) {
    for (int x: arr)
        cout << x << " ";
    cout << endl;
}

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

Node* mirror(Node* root) {
    queue<Node*> levelNodes;
    levelNodes.push(root);

    while (!levelNodes.empty()) {
        Node* front = levelNodes.front();
        Node *temp = front->left;
        front->left = front->right;
        front->right = temp;

        if (front->left)
            levelNodes.push(front->left);

        if (front->right)
            levelNodes.push(front->right);

        levelNodes.pop();
    }

    return root;
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

    vector<int> res = levelOrder(root);
    cout << "Level Order Traversal of current Tree: ";
    printArray(res);

    root = mirror(root);
    res = levelOrder(root);
    cout << "Level Order Traversal of Mirror Tree: ";
    printArray(res);

    return 0;
}

