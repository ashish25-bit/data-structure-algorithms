// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

#include <bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY: O(n^2)
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
    if (root == NULL)
        return 1;
        
    int lSubtree = height(root->left);
    int rSubtree = height(root->right);

    int diff = abs(lSubtree - rSubtree);
    
    if (diff <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    return 0;
}

// TIME COMPLEXITY: O(n)
bool isBalancedUtil(Node* root, int &height) {
    if (!root) {
        height = 0;
        return true;
    }

    int leftHeight  = 0;
    int rightHeight = 0;

    bool leftStatus  = isBalancedUtil(root->left, leftHeight);
    bool rightStatus = isBalancedUtil(root->right, rightHeight);

    height = (leftHeight >= rightHeight ? leftHeight : rightHeight) + 1;

    if (abs(rightHeight - leftHeight) >= 2)
        return false;
    return leftStatus && rightStatus;
}

bool isBalanced(Node* root) {
    int h = 0;
    return isBalancedUtil(root, h);
}