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