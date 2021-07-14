// https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1

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

vector<Node*> insertNode(Node *head, Node *tail, int data) {
    Node *newnode = new Node(data);

    if (head == NULL)
        return {newnode, newnode};

    tail->next = newnode;
    return {head, newnode};
}

Node* findIntersection(Node* head1, Node* head2) {
    Node *head = NULL;
    Node *tail = NULL;
    Node *p1 = head1;
    Node *p2 = head2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->data < p2->data)
            p1 = p1->next;

        else if (p2->data < p1->data)
            p2 = p2->next;

        else {
            vector<Node*> nodes = insertNode(head, tail, p1->data);
            p1 = p1->next;
            p2 = p2->next;
            head = nodes[0];
            tail = nodes[1];
        }
    }

    return head;
}

int main() {
    int n, temp, m;
    cout << "Enter the value for n and m: \t";
    cin >> n >> m;

    // ensuring atleast 5 elements
    if (n<5)
        n = 5;
    if (m<5)
        m = 5;

    SingleLinkedList* llist = new SingleLinkedList();
    cout << "Enter " << n << " digits for linked list 1\n";
    for (int i=0; i<n; i++) {
        cin >> temp;
        llist->head = insertNode(llist->head, temp);
    }

    SingleLinkedList* llist2 = new SingleLinkedList();
    cout << "Enter " << m << " digits for linked list 2\n";
    for (int i=0; i<m; i++) {
        cin >> temp;
        llist2->head = insertNode(llist2->head, temp);
    }

    SingleLinkedList* intersection = new SingleLinkedList();
    intersection->head = findIntersection(llist->head, llist2->head);
    cout << "Intersection of the linked list: ";
    printLL(intersection->head);

    return 0;
}
