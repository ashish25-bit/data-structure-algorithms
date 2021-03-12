struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

Node *copyList(Node *head) {
    Node* newHead = new Node(head->data);
    Node* temp = head->next;
    Node* prev = newHead;
    
    while (temp) {
        Node* newNode = new Node(temp->data);
        prev->next = newNode;
        prev = newNode;
        temp = temp->next;
    }
    
    temp = head;
    prev = newHead;
    
    while (temp && prev) {
        head = head->next;
        prev->arb = temp;
        temp->next = prev;
        temp = head;
        prev = prev->next;
    }
    
    temp = newHead;
    while (temp) {
        if (temp->arb->arb)
            temp->arb = temp->arb->arb->next;
        else temp->arb = NULL;
        temp = temp->next;
    }
    
    temp = newHead;
    while (temp) {
        cout << "Data: " << temp->data << " Random: ";
        if (temp->arb) cout << temp->arb->data << endl;
        else cout << "-1\n";
        temp = temp->next;
    }
    
    return newHead;
}