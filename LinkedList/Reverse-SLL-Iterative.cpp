/**
 * Input:
 1->2->3->4->5
 * Output:
 5->4->3->2->1
 */

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

Node* insertNode(Node* head, int data) {
    Node* newNode = new Node(data);
    Node* temp = head;

    // if head is NULL
    if (!head)
        return newNode;

    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

void printLL(Node* head) {
    while (head->next) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << head->data;
}

Node* reverseList(Node* head) {
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    int n, temp;
    cout << "Enter the number of elements needed in the list\n";
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

    cout << "Linked List is \n";
    printLL(llist->head);

    llist->head = reverseList(llist->head);

    cout << "\nReversed Linked List is \n";
    printLL(llist->head);
    return 0;
}
