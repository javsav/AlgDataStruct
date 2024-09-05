#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <cstddef>

class LinkedList {

 private:
  size_t size = 0;
  Node* head;
  Node* end;

 public:
  LinkedList();
  LinkedList(int* array, int len);
  int get(int position);


};

#endif