// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int val) {
            this->data = val;
            this->next = nullptr;
        }
};
class SingleLinkedList {
    public:
        Node* head;
        SingleLinkedList() {
            this->head = nullptr;
        }
};

void removeLoop(Node* slow, Node* head) {
    Node* ptr1 = head;
    Node* ptr2 = slow;

    while (ptr1 != ptr2) {
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
    }

    while (ptr2->next != ptr1)
        ptr2 = ptr2->next;
    ptr2->next = nullptr;
}

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

void addLoop(Node* head) {
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = head;
}

void hasLoop(Node* head) {
    Node* fast_ptr = head;
    Node* slow_ptr = head;

    while (slow_ptr && fast_ptr && fast_ptr->next) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if (slow_ptr == fast_ptr) {
            cout << "Loop Found \n";
            removeLoop(slow_ptr, head);
            break;
        }
    }
}

int main() {

    int n, temp;
    cout << "Enter the number of elements needed in the list\n";
    cin >> n;

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

    srand(time(0));
    int random = (rand() % n) + 1;
    // add the loop if the random number is o
    if (random % 2) {
        cout << endl << "Loop Added \n";
        addLoop(llist->head);
    }

    hasLoop(llist->head);

    cout << "Linked List: ";
    printLL(llist->head);

    return 0;
}
