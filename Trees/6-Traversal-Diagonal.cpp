#include <bits/stdc++h>
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

void diagonalTraversal(Node* root) {
    queue<Node*> current;
    queue<Node*> next;
    current.push(root);

    while (!current.empty()) {
        Node* temp = current.front();
        current.pop();
        
        if (temp->right) 
            current.push(temp->right);
        if (temp->left)
            next.push(temp->left);
        
        cout << temp->data << " ";
        
        if (current.empty())
            swap(current, next);
    }
}
