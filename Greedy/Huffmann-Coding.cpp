#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    char ch;
    Node *left;
    Node *right;

    Node(int val) {
        this->data = val;
        this->ch = ' ';
        this->left = nullptr;
        this->right = nullptr;
    }

    Node(int val, char c) {
        this->data = val;
        this->ch = c;
        this->left = nullptr;
        this->right = nullptr;
    }
};

struct comparator {
    bool operator() (Node *n1, Node *n2) {
        return n1->data > n2->data;
    }
};

Node * huffmanTree(priority_queue<Node *, vector<Node *>, comparator> &minHeap) {
    while (minHeap.size() != 1) {
        Node *left = minHeap.top();
        minHeap.pop();
        Node *right = minHeap.top();
        minHeap.pop();

        Node *newNode = new Node(right->data + left->data);
        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    return minHeap.top();
}

void huffmanCodes(Node *root, string str) {
    if (!root) return;

    huffmanCodes(root->left, str + "0");
    if (!root->left && !root->right)
        cout << root->ch << ": " << str << endl;
    huffmanCodes(root->right, str + "1");
}

int main() {
    string str = "abcdef";
    int n = str.length();
    vector<int> f = {5, 9, 12, 13, 16, 45};

    priority_queue<Node *, vector<Node *>, comparator> minHeap;

    for (int i=0; i < f.size(); i++) {
        Node *newNode = new Node(f[i], str[i]);
        minHeap.push(newNode);
    }

    Node *root = huffmanTree(minHeap);
    huffmanCodes(root, "");

    return 0;
}
