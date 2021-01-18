unordered_set<string> hashSet;
// string: left node + "-" + root node + "-" + right node

// 3 4 N 7 2 N 3 1 N 4 6

bool dupSub(Node *root) {
    if (!root) return false;
    
    string str = "";
    Node *leftNode = root->left;
    Node *rightNode = root->right;
    
    if (!leftNode && !rightNode)
        return false;

    if (leftNode)
        str = str + std::to_string(leftNode->data) + "-";

    str += std::to_string(root->data);
    
    if (rightNode)
        str = str + "-" + std::to_string(rightNode->data);
        
    if (hashSet.find(str) != hashSet.end())
        return true;

    hashSet.insert(str);    
    
    bool leftSubtreeDuplicateStatus = dupSub(root->left);
    if (leftSubtreeDuplicateStatus) return true;

    bool rightSubtreeDuplicateStatus = dupSub(root->right);
    if (rightSubtreeDuplicateStatus) return true;

    return false;
}