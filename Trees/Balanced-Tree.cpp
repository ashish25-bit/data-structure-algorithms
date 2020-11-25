#include <bits/stdc++.h>
using namespace std;

int height(Node* node){
    if (node == NULL)
        return 0;

    int leftSubtree = height(node->left);
    int rightSubtree = height(node->right);

    if (leftSubtree > rightSubtree)
        return (leftSubtree + 1);
    return (rightSubtree + 1);
}

// This function should return tree if passed  tree 
// is balanced, else false. 
bool isBalanced(Node *root) {
    if (root == NULL
        return 1;
        
    int lSubtree = height(root->left);
    int rSubtree = height(root->right);

    int diff = abs(lSubtree - rSubtree);
    
    if (diff <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    return 0;
}
