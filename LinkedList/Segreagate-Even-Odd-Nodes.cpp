struct Node {
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* divide(int N, Node *head){
    vector<int> odd;
    Node* t = head;
    
    // calculating number of odd numbers
    while(t) {
        if (t->data % 2)
            odd.push_back(t->data);
        t = t->next;
    }
    
    // linked list containing either all odd or even numbers
    if (odd.size() == N || odd.size() == 0)
        return head;
    
    Node* t2 = head;
    t = head;
    
    while (t && t2) {
        if (t2->data % 2 == 1) {
            t2 = t2->next;
            continue;
        }
        
        int temp = t->data;
        t->data = t2->data;
        t2->data = temp;
        t = t->next;
        t2 = t2->next;
    }
    
    if (t) {
        for (int x: odd) {
            t->data = x;
            t = t->next;
        }
    }
    
    return head;
}