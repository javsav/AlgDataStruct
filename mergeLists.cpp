#include <random>
#include <iostream>
#include <ctime>

struct ListNode {
      ListNode(int val, ListNode* next) : val(val), next(next) {}
      ListNode(int val) : ListNode(val, nullptr) {}
      int val;
      struct ListNode *next;
 };

ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
  ListNode* current = list2;
  
  if (list1->val < list2->val) {
    current = list1;
    list1 = list1->next;
  } else {
    list2 = list2->next;
  }

  ListNode* newHead = current;

  while (list1 && list2) {
    if (list1->val < list2->val) {
      current->next = list1;
      list1 = list1->next;
      current = current->next;
    } else {
      current->next = list2;
      list2 = list2->next;
      current = current->next;
    }
  }


    while (list1) {
      current->next = list1;
      list1 = list1->next;
      current = current->next;
    }
 
    while (list2) {
      current->next = list2;
      list2 = list2->next;
      current = current->next;
    }
    
  

  current->next = nullptr;

  return newHead;    
}

ListNode* reverseList (ListNode* list) {
  ListNode* current = list;
  ListNode* previous = nullptr;
  ListNode* next;

  while (current != nullptr) {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }

  return previous;  
}



 int main() {
  //srand(time(NULL));
  int n = 10;
  
  ListNode* head = new ListNode(rand() % n);
  ListNode* next = head;
  for (int count = 0; count < n; count++) {
    ListNode* newNode = new ListNode(rand() % n);
    next->next = newNode;
    next = newNode;    
  }

  next = nullptr;

  for (ListNode* iterator = head; iterator != nullptr; iterator = iterator->next) {
    std::cout << iterator->val << " ";
  }

  std::cout << "\n";

  ListNode* head2 = new ListNode(rand() % n);
  next = head2;
  for (int count = 0; count < n; count++) {
    ListNode* newNode = new ListNode(rand() % n);
    next->next = newNode;
    next = newNode;    
  }

  for (ListNode* iterator = head2; iterator != nullptr; iterator = iterator->next) {
    std::cout << iterator->val << " ";
  }

  std::cout << "\n";

  ListNode* newList = mergeTwoLists(head, head2);

  for (ListNode* iterator = newList; iterator != nullptr; iterator = iterator->next) {
    std::cout << iterator->val << " ";
  }

  std::cout << "\n";

  ListNode* reversedList = reverseList(newList);

  for (ListNode* iterator = reversedList; iterator != nullptr; iterator = iterator->next) {
    std::cout << iterator->val << " ";
  }

  std::cout << "\n";


 }

