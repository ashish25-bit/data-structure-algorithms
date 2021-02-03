/**
 * Suppose the lists are:
 * 1->2->3
 * 4->5
 * 5->6
 * 7->8
 * 
 * Then Node* arr = [1, 4, 5, 7] which are the heads of each linked list
 */

Node * mergeKLists(Node *arr[], int N) {
    priority_queue<Node*, vector<Node*>, comparator> minHeap;
    
    for (int i=0; i < N; i++)
        minHeap.push(arr[i]);
    
    Node *head = NULL;
    Node *prev = NULL;
    
    while (!minHeap.empty()) {
        
        Node *current = minHeap.top();
        minHeap.pop();
        
        if (head == NULL) {
            head = current;
            prev = NULL;
        }
        else {
            prev->next = current;
            prev = prev->next;
        }
        
        if (current->next)
            minHeap.push(current->next);
    }
    return head;
}