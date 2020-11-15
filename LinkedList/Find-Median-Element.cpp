#include <bits/stdc++.h>
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

Node* findMedian(Node* head) {
    int n = 0, pos = 1;
    int medianPosition;
    Node* temp = head;

    while (temp) {
        n++;
        temp = temp->next;
    }

    medianPosition = n/2 + 1;
    temp = head;

    while (pos++ != medianPosition)
        temp = temp->next;

    return temp;
}

int main() {
    int n, temp;
    cout << "Enter the value for n: \t";
    cin >> n;

    // ensuring atleast 5 elements
    if (n<5)
        n = 5;

    SingleLinkedList* llist = new SingleLinkedList();
    cout << "Enter " << n << " digits for linked list 1\n";
    for (int i=0; i<n; i++) {
        cin >> temp;
        llist->head = insertNode(llist->head, temp);
    }

    Node* median = findMedian(llist->head);
    printLL(median);

    return 0;
}
