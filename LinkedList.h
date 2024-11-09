#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.tpp"
#include <cstddef>
#include <vector>
#include <iostream>
template <typename T>
class LinkedList {

 private:
  Node<T>* head;
  Node<T>* tail;
  size_t size = 0;
  Node<T>* search(T value);

 public:
  LinkedList();
  LinkedList(std::vector<T> list);
  void print();
  void push_front(T data);
  void push_back(T data);
  void insert(int index, T value);
  void deleteValue(T value);
  void printTail();
  void printHead();
};

template <typename T>
Node<T>* LinkedList<T>::search(T value) {
  Node<T>* current = head;

  while (current != nullptr) {
    if (current->data == value) {
      return current;
    }
    current = current->next;
  }
  return nullptr;
}

template <typename T>
LinkedList<T>::LinkedList() {
  head = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(std::vector<T> list) {
  auto i = list.begin();
  head = new Node<T>(*i);
  Node<T>* current = head;  
  i++;
  size++;

  while (i != list.end()) {
    Node<T>* newNode = new Node<T>(*i);
    current->next = newNode;
    newNode->previous = current;    
    current = newNode;
    i++;
    size++;
  }

  tail = current;

  return;
}

template <typename T>
void LinkedList<T>::print() {
  Node<T>* current = head;
  std::cout << '[';
  while (current != nullptr) {
    if (current == tail) {
      std::cout << current->data << ']';
    } else {
      std::cout << current->data << ' ';
    }
    current = current->next;
  }
  std::cout << "\n";
}

template <typename T>
void LinkedList<T>::push_front(T data) {
  if (!head) {
    head = new Node<T>(data);
    return;
  }
  Node<T>* oldHead = head;
  head = new Node<T>(data, oldHead);
  size++;
  oldHead->previous = head;
}

template <typename T>
void LinkedList<T>::push_back(T data) {
tail->next = new Node<T>(data, nullptr, tail);
tail = tail->next;
}


template <typename T>
inline void LinkedList<T>::insert(int index, T value) {
  int i = 0;
  Node<T>* current = head;
  while (i < index && current != nullptr) {
    current = current->next;
    i++;
  }

  if (i != index) {
    return;
  }

  Node<T>* previous = current->previous;
  Node<T>* newNode = new Node<T>(value, current, previous);
  size++;
  previous->next = newNode;
  current->previous = newNode;


}

template <typename T>
void LinkedList<T>::deleteValue(T value) {
  Node<T>* delNode = search(value);

  Node<T>* previous = delNode->previous;
  Node<T>* next = delNode->next;

  delete delNode;

  if (previous == nullptr) {
    head = next;
  } else {
    previous->next = next;
  }

  if (next == nullptr) {
    tail = previous;
  } else {
    next->previous = previous;
  }
}

template <typename T>
inline void LinkedList<T>::printTail() {
  std::cout << tail->data << '\n';
}

template <typename T>
inline void LinkedList<T>::printHead() {
  std::cout << head->data << '\n';
}

#endif



