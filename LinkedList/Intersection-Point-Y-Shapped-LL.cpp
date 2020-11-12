#include <bits/stdc++.h>
using namespace std;

int lengthLL(Node* head) {
    if (head == NULL)
        return 0;
        
    int count = 0;
    while (head != NULL && ++count)
        head = head->next;
        
    return count;
}


int intersectPoint(Node* head1, Node* head2) {
    int l1 = lengthLL(head1);
    int l2 = lengthLL(head2);
    Node *p1 = head1;
    Node *p2 = head2;
    
    if (l1 > l2) {
        int moves = 0;
        while (++moves <= l1-l2) 
            p1 = p1->next;
    }
    
    if (l1 < l2) {
        int moves = 0;
        while (++moves <= l2-l1)
            p2 = p2->next;
    }
    
    while (p1 != NULL && p2 != NULL) {
        if (p1 == p2) 
            return p1->data;
        p1 = p1->next;
        p2 = p2->next;
    }
    return -1;
}   
