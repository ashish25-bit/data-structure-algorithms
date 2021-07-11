// https://practice.geeksforgeeks.org/problems/sum-tree/1#

#include <bits/stdc++.h>
using namespace std;

// Time complexity O(N^2)
int subTreeSum(Node* root) {
    if (!root) return 0;
    
    int sum = root->data + subTreeSum(root->left) + subTreeSum(root->right);
    return sum;
}

bool isSumTree(Node* root) {
    // check for this input
    // 62 16 15 N 8 4 7 N 8 4
    
    if (!root || (!root->left && !root->right))
        return true;
        
    int sum = subTreeSum(root->left) + subTreeSum(root->right);
     
    if (sum == root->data && isSumTree(root->left) && isSumTree(root->right))
        return true;
    return false;
}

// Time complexity O(N)
bool sumTree(Node* root, int &sum) {
    if (!root->left && !root->right) {
        sum = root->data;
        return true;
    }

    int leftSum  = 0;
    int rightSum = 0;

    bool leftStatus  = root->left  ? sumTree(root->left, leftSum) : true;
    bool rightStatus = root->right ? sumTree(root->right, rightSum) : true;

    sum = leftSum + rightSum + root->data;

    if (leftStatus && rightStatus && leftSum + rightSum == root->data)
        return true;
    return false;
}
bool isSumTree(Node* root) {
    if (!root) return false;

    int sum = 0;
    return sumTree(root, sum);
}
