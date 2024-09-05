#include "LinkedList.h"

LinkedList::LinkedList() {

  Node* newNode = new Node;
  this->head = newNode;
  this->end = newNode;
  newNode->setNext(nullptr);
  size++;

}

LinkedList::LinkedList(int* array, int len) {
  Node* head = new Node(array[0]);
  this->head = head;
  Node* tempNext = head;
  size++;

  for (int i = 1; i < len; i++) {    
    Node* newNode = new Node(array[i]);
    tempNext->setNext(newNode);
    tempNext = newNode;
    size++;  
    if (i == len - 1) {
      this->end = newNode;
      newNode->setNext(nullptr);
    }
  }

} 

int LinkedList::get(int position) {
  if (position > size - 1) {
    return -1;
  }

  int count = 0;
  Node* iterator = head;

  while (count < position) {
    iterator = iterator->getNext();
    count++;
  }

  return iterator->getData();
}