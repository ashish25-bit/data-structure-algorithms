// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

// space complexity: O(N)
// Node *copyList(Node *head) {
//     unordered_map<Node*, Node*> hashMap;
//     Node* temp = head;
//     Node* newHead = NULL;

//     while (temp) {
//         Node* newNode = new Node(temp->data);

//         if (!newHead)
//             newHead = newNode;

//         hashMap[temp] = newNode;
//         temp = temp->next;
//     }

//     temp = head;
//     while (temp) {
//         if (temp->next) {
//             hashMap[temp]->next = hashMap[temp->next];
//         }
//         if (temp->arb) {
//             hashMap[temp]->arb = hashMap[temp->arb];
//         }
//         temp = temp->next;
//     }

//     return newHead;
// }

// space complexity: O(1)
Node *copyList(Node *head) {
    Node* node = head;
    Node* newHead = NULL;

    while (node) {
        Node* newNode = new Node(node->data);

        if (!newHead) {
            newHead = newNode;    
        }

        Node* temp = node->next;
        node->next = newNode;
        newNode->next = temp;

        node = temp;
    }

    node = head;
    while (node) {
        if (node->arb) {
            node->next->arb = node->arb->next;
        }
        node = node->next->next;
    }

    node = head;
    while (node) {
        Node* temp = node->next->next;
        node->next->next = temp ? temp->next : NULL;
        node->next = temp;
        node = temp;
    }

    return newHead;
}



int main() {
    Node* root = new Node(1);

    Node* newNode1 = new Node(2);
    Node* newNode2 = new Node(3);
    Node* newNode3 = new Node(4);

    root->next = newNode1;
    newNode1->next = newNode2;
    newNode2->next = newNode3;

    root->arb = newNode1;
    newNode1->arb = newNode3;

    Node* newRoot = copyList(root);
    print(newRoot);

    return 0;
}