// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

#include <bits/stdc++.h>
using namespace std;

// class Node {
//     public: 
//         int data;
//         Node* left;
//         Node* right;

//         Node (int val) {
//             this.data = val;
//             this.left = nullptr;
//             this.right = nullptr;
//         }
// }

void zigZagTraversal(Node* root) {
    stack<Node*> current;
    stack<Node*> next;
    current.push(root);
    bool leftToRight = true;

    while (!current.empty()) {
        Node* top = current.top();
        current.pop();

        cout << top->data << " ";
        if (leftToRight) {
            if (top->left)
                next.push(top->left);
            if (top->right)
                next.push(top->right);
        }
        else {
            if (top->right)
                next.push(top->right);
            if (top->left)
                next.push(top->left);
        }

        if (current.empty()) {
            swap(current, next);
            leftToRight = !leftToRight;
        }

    }

}