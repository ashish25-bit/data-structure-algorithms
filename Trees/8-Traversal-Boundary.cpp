// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

void leftBoundary(Node *root, vector<int> &res) {
    if (!root)
        return;
    
    if (root->left || root->right)
        res.push_back(root->data);
        
    if (root->left)
        leftBoundary(root->left, res);
    else if (root->right)
        leftBoundary(root->right, res);
}

void leafNode(Node *root, vector<int> &res) {
    if (!root)
        return;
    
    leafNode(root->left, res);
    
    if (!root->left && !root->right)
        res.push_back(root->data);
        
    leafNode(root->right, res);
}

void rightBoundary(Node *root, vector<int> &res) {
    if (!root)
        return;
        
    if (root->right)
        rightBoundary(root->right, res);
    else if (root->left)
        rightBoundary(root->left, res);
        
    if (root->left || root->right)
        res.push_back(root->data);
}

vector <int> printBoundary(Node *root) {
    vector<int> res;
     
    if (!root)
        return res;
    
    res.push_back(root->data);
    
    if (!root->left && !root->right)
        return res;
        
    leftBoundary(root->left, res);
    leafNode(root, res);
    rightBoundary(root->right, res);
    
    return res;
}

int main() {
    
    return 0;
}