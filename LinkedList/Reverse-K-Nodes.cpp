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
    cout << head->data << endl;
}

Node* reverseKNodes(Node* root, int k) {
    int count = 0;
    Node* current = root;
    Node* next = current;
    Node* prev = nullptr;

    while (current && count < k) {
        count++;
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    if (next)
        root->next = reverseKNodes(next, k);

    return prev;
}

int main() {

    int n, temp, k;
    cout << "Enter the value for n and k: \t";
    cin >> n >> k;

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

    llist->head = reverseKNodes(llist->head, k);
    cout << "Linked List After Rotation: ";
    printLL(llist->head);

    return 0;
}
