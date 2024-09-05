#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <cstddef>

class LinkedList {

 private:
  size_t size;
  Node* start;
  Node* end;

 public:
  LinkedList();
  LinkedList(int* array, int len);


};

#endif