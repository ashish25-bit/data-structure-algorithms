#include <bits/stdc++.h>
using namespace std;

class Node {
    public: 
        int data;
        Node* left;
        Node* right;

        Node (int val) {
            data = val;
            left = nullptr;
            right = nullptr;
        }
};

void diagonalTraversal(Node* root) {
    Node* curr = root;
    queue<Node*> next;

    while (curr) {
        cout << curr->data << " ";

        if (curr->left)
            next.push(curr->left);

        if (curr->right)
            curr = curr->right;
        else {
            if (!next.empty()) {
                curr = next.front();
                next.pop();
            }
            else curr = NULL;
        }
    }
}

int main() {
    Node*  root = new Node(8);

    root->left = new Node(3);
    root->right = new Node(10);

    root->left->left = new Node(1);

    root->right->left = new Node(6);
    root->right->right = new Node(14);

    root->right->left->left = new Node(4);
    root->right->left->right = new Node(7);

    root->right->right->left = new Node(13);

    diagonalTraversal(root);

    return 0;    
}
