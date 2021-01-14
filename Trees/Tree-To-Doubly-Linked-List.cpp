void treeToDLL(Node *root, Node **head) {
    if (!root)
        return;
    
    static Node* prev = NULL;
    
    treeToDLL(root->left, head);
    
    if (!prev)
        *head = root;
    
    else {
        root->left = prev;
        prev->right = root;
    }
    
    prev = root;
    treeToDLL(root->right, head);
}

Node * bToDLL(Node *root) {
    Node *head = NULL;
    treeToDLL(root, &head);
    return head;
}