// https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

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
    if (head == NULL)
            return NULL;
        
    Node* slow = head;
    Node* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
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
