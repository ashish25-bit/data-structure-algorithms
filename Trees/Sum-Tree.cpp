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

int sumTree(Node *root) {
    if (!root)
        return 0;

    int curr_val = root->data;
    int l_subtree_sum = sumTree(root->left);
    int r_subtree_sum = sumTree(root->right);

    root->data = l_subtree_sum + r_subtree_sum;
    return curr_val + l_subtree_sum + r_subtree_sum;
}

int main() {
    vector<int> vec = {10, -2, 6, 8, -4, 7, 5};
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

    int sum = sumTree(root);

    res = levelOrder(root);
    cout << "Level Order Traversal of the Sum Tree: ";
    printArray(res);

    return 0;
}
