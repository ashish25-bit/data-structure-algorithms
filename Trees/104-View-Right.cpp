// https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

int getHeight(Node *root) {
    if (!root)
        return 0;
    
    int leftSubtree = getHeight(root->left);
    int rightSubtree = getHeight(root->right);
    
    if (leftSubtree > rightSubtree)
        return leftSubtree + 1;
    return rightSubtree + 1;
}

// Should return  right view of tree
vector<int> rightView(Node *root) {
    if (!root)
        return {};
    
    int max_level = getHeight(root);
    vector<int> res(max_level, -1);
    queue< pair<Node *, int>> level;
    
    level.push(std::make_pair(root, 0));
    
    while (!level.empty()) {
        pair<Node *, int> pairNode = level.front();
        level.pop();
        
        Node *node = pairNode.first; // current node
        int l = pairNode.second; // current level node
        
        if (node->left) 
            level.push(std::make_pair(node->left, l+1));
            
        if (node->right)
            level.push(std::make_pair(node->right, l+1));
        
        if (node)
            res[l] = node->data;
    }
    
    return res;
}