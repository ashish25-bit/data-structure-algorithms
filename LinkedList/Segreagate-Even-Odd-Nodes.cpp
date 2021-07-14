// https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

// Space: O(N)
// Node* divide(int N, Node *head){
//     vector<int> odd;
//     Node* t = head;

//     // calculating number of odd numbers
//     while(t) {
//         if (t->data % 2)
//             odd.push_back(t->data);
//         t = t->next;
//     }

//     // linked list containing either all odd or even numbers
//     if (odd.size() == N || odd.size() == 0)
//         return head;

//     Node* t2 = head;
//     t = head;

//     while (t && t2) {
//         if (t2->data % 2 == 1) {
//             t2 = t2->next;
//             continue;
//         }

//         int temp = t->data;
//         t->data = t2->data;
//         t2->data = temp;
//         t = t->next;
//         t2 = t2->next;
//     }

//     if (t) {
//         for (int x: odd) {
//             t->data = x;
//             t = t->next;
//         }
//     }

//     return head;
// }

// space: O(1)
Node* divide(Node *head) {
    Node* evenHead = NULL;
    Node* evenTail = NULL;
    Node* oddHead  = NULL;
    Node* oddTail  = NULL;

    Node* curr = head;

    while (curr) {
        int val = curr->data;

        if (val % 2) {
            if (!oddHead) {
                oddHead = curr;
                oddTail = curr;
            }
            else {
                oddTail->next = curr;
                oddTail = curr;
            }
        }
        else {
            if (!evenHead) {
                evenHead = curr;
                evenTail = curr;
            }
            else {
                evenTail->next = curr;
                evenTail = curr;
            }
        }
        curr = curr->next;
    }

    if (!oddHead) return evenHead;
    if (!evenHead) return oddHead;

    evenTail->next = oddHead;
    oddTail->next = NULL;
    return evenHead;
}

int main() {
    Node* root = new Node(17);
    root->next = new Node(15);
    root->next->next = new Node(8);
    root->next->next->next = new Node(9);
    root->next->next->next->next = new Node(2);
    root->next->next->next->next->next = new Node(4);
    root->next->next->next->next->next->next = new Node(6);

    root = divide(root);

    while (root) {
        cout << root->data << " ";
        root = root->next;
    }

    return 0;
}
