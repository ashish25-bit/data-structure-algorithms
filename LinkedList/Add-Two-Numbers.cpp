#include <bits/stdc++.h>
using namespace std;

class ListNode {
  public:
    int data;
    ListNode* next;
    ListNode(int val) {
      this->data = val;
      this->next = NULL;
    }
};

ListNode* getList(vector<int> arr) {
  ListNode* head = NULL;
  ListNode* tail = NULL;

  for (int x: arr) {
    ListNode* newNode = new ListNode(x);

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

void printLL(ListNode* head) {
  while (head) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

// res, carry
pair<int, int> getSumAndCarry(int sum) {
  pair<int, int> res;
  if (sum >= 10) {
    int rem = sum % 10;
    res.first = rem;
    res.second = 1;
  }
  else {
    res.first = sum;
    res.second = 0;
  }
  return res;
}

ListNode* addLL(ListNode* l1, ListNode* l2) {
  int carry = 0;
  vector<int> res;

  while (l1 && l2) {
    int sum = l1 -> data + l2->data + carry;
    pair<int, int> sum_carry = getSumAndCarry(sum);
    res.push_back(sum_carry.first);
    carry = sum_carry.second;

    l1 = l1->next;
    l2 = l2->next;
  }

  while (l1) {
    int sum = l1->data + carry;
    
    pair<int, int> sum_carry = getSumAndCarry(sum);
    res.push_back(sum_carry.first);
    carry = sum_carry.second;

    l1 = l1->next;
  }

  while (l2) {
    int sum = l2->data + carry;
    
    pair<int, int> sum_carry = getSumAndCarry(sum);
    res.push_back(sum_carry.first);
    carry = sum_carry.second;

    l2 = l2->next;
  }
  if (carry == 1) res.push_back(carry);

  return getList(res);
}

int main() {
  // vector<int> l1 = {2, 4, 3};
  // vector<int> l2 = {5, 6, 4};

  vector<int> l1 = {9, 9};
  vector<int> l2 = {0, 1};

  // vector<int> l1 = {1};
  // vector<int> l2 = {9, 9, 9};

  ListNode* h1 = getList(l1);
  ListNode* h2 = getList(l2);

  printLL(h1);
  printLL(h2);

  ListNode* res =addLL(h1, h2);
  printLL(res);

  return 0;
}
