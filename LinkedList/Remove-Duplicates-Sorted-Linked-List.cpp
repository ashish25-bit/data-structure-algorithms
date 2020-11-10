#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int val) {
            this->data = val;
            this->next = NULL;
        }
};

class SingleLinkedList {
    public:
        Node* head;
        SingleLinkedList() {
            this->head = NULL;
        }
};

void printLL(Node* head) {
    while (head->next) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << head->data << endl;
}

Node* insertNode(Node* head, int data) {
    Node* newNode = new Node(data);
    Node* temp = head;
    // if head is NULL
    if (!head)
        return newNode;

    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

Node* removeDuplicates(Node* root) {
    Node* F = root;
    Node* S = root->next;

    while (F && S) {
        if (F->data != S->data) {
            F = F->next;
            S = S->next;
            continue;
        }

        Node* temp = S;
        F->next = temp->next;
        S = S->next;
        free(temp);
    }
    return root;
}

int main() {
    int n, temp;
    cout << "Enter the number of elements needed in the list: \t";
    cin >> n;

    // ensuring atleast 5 elements
    if (n<5)
        n = 5;

    SingleLinkedList* llist = new SingleLinkedList();
    cout << "Enter " << n << " digits for linked list\n";
    for (int i=0; i<n; i++) {
        cin >> temp;
        llist->head = insertNode(llist->head, temp);
    }

    cout << "Linked List: ";
    printLL(llist->head);

    llist->head = removeDuplicates(llist->head);
    cout << "Linked List After Removing Duplicates: ";
    printLL(llist->head);

    return 0;
}
