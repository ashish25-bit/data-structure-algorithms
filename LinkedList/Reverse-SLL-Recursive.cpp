/**
 * Input:
 1->2->3->4->5
 * Output:
 5->4->3->2->1
 */

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

void printLL(Node* head) {
    while (head->next) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << head->data;
}

Node* reverseUtil(Node* curr, Node* prev) {
    if (!curr) return prev;

    Node* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;

    return reverseUtil(curr, prev);
}

Node* reverseList(Node* head) {
    return reverseUtil(head, NULL);
}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5};

    SingleLinkedList* llist = new SingleLinkedList();

    for (int x: arr)
        llist->head = insertNode(llist->head, x);

    cout << "Linked List is \n";
    printLL(llist->head);

    llist->head = reverseList(llist->head);

    cout << "\nReversed Linked List is \n";
    printLL(llist->head);
    return 0;
}