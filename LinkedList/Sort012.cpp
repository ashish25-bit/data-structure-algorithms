// class Node {
//     int data;
//     Node *next;

//     Node(int x) {
//         this.data = x;
//         this.next = NULL;
//     }
// };

Node* segregate(Node *head) {
    vector<int> count = {0, 0, 0};
    
    Node *temp = head;
    while (temp) {
        count[temp->data]++;
        temp = temp->next;
    }
    
    temp = head;
    int pos = 0;
    
    while (temp) {
        if (count[pos] == 0) {
            pos++;
            continue;
        }
            
        temp->data = pos;
        count[pos]--;
        temp = temp->next;
    } 
    
    return head;
}