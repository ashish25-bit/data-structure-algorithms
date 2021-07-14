// https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

int getNthFromLast(Node *head, int n) {
    int count = 1;
    Node *pointer1 = head;
    
    while (count++ < n && pointer1)
        pointer1 = pointer1->next;
        
    if (!pointer1)
        return -1;
    
    while (pointer1->next) {
        head = head->next;
        pointer1 = pointer1->next;
    }
    
    return head->data;
}