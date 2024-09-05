#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {

  Node* newNode = new Node;
  this->head = newNode;
  this->tail = newNode;
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
      this->tail = newNode;
      newNode->setNext(nullptr);
    }
  }

} 

int LinkedList::get(int position) {
  if (position > size || position < 1) {
    return __INT32_MAX__;
  }

  int count = 1;
  Node* iterator = head;

  while (count < position) {
    iterator = iterator->getNext();
    count++;
  }

  return iterator->getData();
}

void LinkedList::insertPosition(int position, int newNum) {

  

  if (position <= 1) {
    Node* newNode = new Node(newNum);
    newNode->setNext(this->head);
    this->head = newNode;
    this->size++;

  } else if (position >= this->size) {
    position = this->size;
    Node* newNode = new Node(newNum);
    this->tail->setNext(newNode);
    newNode->setNext(nullptr);
    this->tail = newNode;
    this->size++;

  } else {
    int count = 1;
    Node* iterator = head;
    Node* beforeInsert;

    while (count < position) {    
      if (count == position - 1) {
        beforeInsert = iterator;
      }

      iterator = iterator->getNext();
      count++;    
    }
    Node* newNode = new Node(newNum);
    beforeInsert->setNext(newNode);
    newNode->setNext(iterator);
    this->size++;

  }
}

int LinkedList::begin() {
return head->getData();
}
int LinkedList::end() {
return tail->getData();
}

int LinkedList::search(int target) {
  int index = 1;
  for (auto i = this->head; i != this->tail->getNext(); i = i->getNext()) {
    if (i->getData() == target) {
      return index;
    }
    index++;
  }
 return -1;
}

void LinkedList::printList() {
  std::cout << "[";
  for (auto i = this->head; i != this->tail->getNext(); i = i->getNext()) {
    if (i == this->tail) {
      std::cout << i->getData();
    } else {
      std::cout << i->getData() << " ";
    }
  }
  std::cout << "]\n";
}

bool LinkedList::deletePosition(int position) {

  if (position <= 0 || position > size) {
    return false;
  }

  int count = 1;
  Node* iterator = head;
  Node* beforeDelete;
  while (count < position) {
    if (count == position - 1) {
        beforeDelete = iterator;
    }
    iterator = iterator->getNext();
    count++;    
  }

  Node* tempNext = iterator->getNext();
  beforeDelete->setNext(tempNext);
  delete iterator;

  if (position == size) {
    this->tail = beforeDelete;
  }
  
  this->size--;
  return true;


}

