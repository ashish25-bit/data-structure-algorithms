struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

Node *compute(Node *head) {
    // reverse the linked list
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
    
    Node* newHead = new Node(head->data);
    Node* temp = head->next;
    int max = head->data;
    
    while (temp) {
        if (max <= temp->data) {
            Node* newNode = new Node(temp->data);
            newNode->next = newHead;
            newHead = newNode;
            max = temp->data;
        }
        temp = temp->next;
    }
    return newHead;
}