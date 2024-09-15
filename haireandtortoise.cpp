#include <iostream>
#include <random>
#include <ctime>

class ListNode {
  public:
  ListNode(int data, ListNode* next) : data(data), next(next) {}
  ListNode(int data) : data(data), next(nullptr) {}

  int data;
  ListNode* next;
};

class CircularList {

  public:
  CircularList() {
    srand(time(NULL));
  }
  ListNode* createCircularList(int length) {
    int cyclePoint = (rand() % length - 2) + 3;
    
    ListNode* head = new ListNode(rand() % 10, nullptr);
    ListNode* next = head;
    ListNode* cycle;
    for (int count = 1; count <= length; count++) {
      ListNode* newNode = new ListNode(rand() % 10);
      if (count == cyclePoint) {
        cycle = newNode;
      }
      next->next = newNode;
      next = newNode;
    }
    next->next = cycle;
    return head;
  }

  void printList(ListNode* head) {
    ListNode* iterator = head;
    while (iterator != nullptr) {
      std::cout << iterator->data << " ";
      iterator = iterator->next;
      std::cin.get();
    }
  }

};

int main() {
  CircularList listMaker;

  ListNode* circularList = listMaker.createCircularList(10);

  ListNode* iterator = circularList;

  ListNode* fast = circularList;
  ListNode* slow = circularList;
  int count = 0;
  while (fast && slow) {
    if (fast == slow && count) {
      break;
    }
    fast = fast->next->next;
    slow = slow->next;
    count++;
  }
  int node = 1;
  slow = circularList;
  while (fast && slow) {
    if (fast == slow) {
      std::cout << "Cycle is at: " << node << "\n";
      break;
    }
    fast = fast->next;
    slow = slow->next;
    node++;
  }
}