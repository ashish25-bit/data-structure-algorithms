/**
 * Suppose the lists are:
 * 1->2->3
 * 4->5
 * 5->6
 * 7->8
 * 
 * Then Node* arr = [1, 4, 5, 7] which are the heads of each linked list
 */

#include<bits/stdc++.h>
using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> MIN_HEAP;

class Node {
  public:
    int data;
    Node* next;
    Node(int val) {
      this->data = val;
      this->next = NULL;
    }
};

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

Node* getLast(Node* node, MIN_HEAP& mh) {
    while (node->next) {
        mh.push(node->data);
        node = node->next;
    }
    mh.push(node->data);
    return node;
}

Node* mergeKLists(Node *arr[], int K) {
    Node* head = arr[0];
    MIN_HEAP minHeap;
    
    Node* tail = getLast(arr[0], minHeap);
    
    for (int i=1; i<K; i++) {
        tail->next = arr[i];
        tail = getLast(arr[i], minHeap);
    }
    
    Node* p = head;
    while (!minHeap.empty()) {
        p->data = minHeap.top();
        minHeap.pop();
        p = p->next;
    }
    
    return head;
}

int main() {
    int n = 4;
    Node* nodes[n];

    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5},
        {5, 6},
        {7, 8} 
    };

    int pos = 0;
    for (vector<int> t: arr) {
        Node* head = getList(t);
        nodes[pos++] = head;
    }

    Node* head = mergeKLists(nodes, n);
    printLL(head);
    
    return 0;
}
