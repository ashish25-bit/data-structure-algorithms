pair <int, int> sumLong(Node* root) {
    if (!root)
        return std::make_pair(0, 0);
    
    pair<int, int> left_subtree = sumLong(root->left);
    pair<int, int> right_subtree = sumLong(root->right);
    
    left_subtree.first = root->data + left_subtree.first;
    right_subtree.first = root->data + right_subtree.first;
    
    left_subtree.second = left_subtree.second + 1;
    right_subtree.second = right_subtree.second + 1;
    
    if (right_subtree.second == left_subtree.second) {
        if (right_subtree.first > left_subtree.first)
            return right_subtree;
        return left_subtree;
    }
    
    if (right_subtree.second > left_subtree.second)
        return right_subtree;
    return left_subtree;
}

int sumOfLongRootToLeafPath(Node* root) {
	pair<int, int> sum = sumLong(root);
	return sum.first;
}