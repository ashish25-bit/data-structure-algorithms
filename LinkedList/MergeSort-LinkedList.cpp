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

void middleNode(Node *curr, Node **first, Node **second) {
    Node* slow = curr;
    Node* fast = curr->next;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *first = curr;
    *second = slow->next;
    slow->next = NULL;
}

Node* mergeList(Node* first, Node* second) {
    if (!first) return second;
    if (!second) return first;
    
    Node* result = NULL;
    
    if (first->data <= second->data) {
        result = first;
        result->next = mergeList(first->next, second);
    }
    else {
        result = second;
        result->next = mergeList(first, second->next);
    }
    return result;
}

void mergeSortUtil(Node** head) {
    Node* curr = *head;
    if (!curr || !curr->next) return;
    
    Node* first;
    Node* second;
    middleNode(curr, &first, &second);
    mergeSortUtil(&first);
    mergeSortUtil(&second);
    *head = mergeList(first, second);
}

//Function to sort the given linked list using Merge Sort.
Node* mergeSort(Node* head) {
    mergeSortUtil(&head);
    return head;
}

Node* getList(vector<int> arr) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int x: arr) {
        Node* newNode = new Node(x);

        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void printLL(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {3, 1, 4, 5, 2};

    Node* head = getList(arr);
    printLL(head);

    head = mergeSort(head);
    printLL(head);
    
    return 0;
}
