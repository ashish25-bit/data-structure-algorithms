#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
};

void splitList(Node *head, Node **head1_ref, Node **head2_ref) {
    Node *slow = head;
    Node *fast = head;
    bool hasCrossedHead = false;
    
    while ((!hasCrossedHead || fast != head) && fast->next != head) {
        slow = slow->next;
        fast = fast->next->next;
        hasCrossedHead = true;
    }
    // printf("%d %d\n", fast->data, slow->data);
    
    // even nodes
    if (fast == head) {
        Node *temp = head;
        while (temp->next != slow)
            temp = temp->next;
            
        temp->next = head;
        *head1_ref = head;
        
        temp = slow;
        while (temp->next != head)
            temp = temp->next;
        temp->next = slow;
        *head2_ref = slow;
        return;
    }
    
    // odd nodes
    Node *temp = head;
    while (temp != slow) temp = temp->next;
    
    Node *temp2 = temp->next;
    temp->next = head;
    *head1_ref = head;
    
    slow = temp2;
    while (temp2->next != head) temp2 = temp2->next;
    temp2->next = slow;
    *head2_ref = slow;
}