vector<int> leftView(Node *root) {
    vector<int> res;
    
    if (!root)
        return res;
    
    queue< pair<Node *, int>> level;
    unordered_set <int> hashSet;
   
    level.push(std::make_pair(root, 0));
   
    while (!level.empty()) {
        pair<Node *, int> pairNode = level.front();
        level.pop();
       
        Node *node = pairNode.first; // current node
        int l = pairNode.second; // current node level
       
        if (node->left) 
            level.push(std::make_pair(node->left, l+1));
            
        if (node->right) 
            level.push(std::make_pair(node->right, l+1));
            
        if (hashSet.find(l) == hashSet.end()) {
            if (node) {
                res.push_back(node->data);
                hashSet.insert(l);                
            }
        }
    }
   
    return res;
}