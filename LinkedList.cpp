#include "LinkedList.h"
#include <iostream>
#include <limits>

LinkedList::LinkedList() {
  // Construct with single value of 0 by default
  Node* newNode = new Node(0, nullptr);
  this->head = newNode;
  this->tail = newNode;
  m_size++;

}

Node* LinkedList::iterate(int position) {
  size_t count = 1;
  for (auto i = this->head; i != nullptr; i = i->next()) {
    if (count++ == position) {
      return i;
    }
  }
  return nullptr;
}

// Create a list of size length with value data
LinkedList::LinkedList(int size, int value) {
  this->head = new Node(value);
  Node* next = this->head;
  m_size++;
  while (m_size++ < size) {
    Node* newNode = new Node(value);
    next->next() = newNode;
    next = newNode;    
  }
  this->tail = next;
  this->tail->next();  
}

// Construct from array
LinkedList::LinkedList(int* array, int len) {
  // Create head from first array item  
  this->head = new Node(array[m_size++]);
  Node* next = this->head;  
  // Iterate through second to last element of array and add to list
  while(m_size < len) {    
    Node* newNode = new Node(array[m_size++]);
    next->next() = newNode;
    next = newNode;    
  }
  this->tail = next;
  this->tail->next();
} 

// Return item at position
int LinkedList::get(int position) {
  // If out of range return max for int
  if (position > m_size || position < 1) {
    return std::numeric_limits<int>::max();
  }
  
  // Otherwise, iterate until position is reached and return data
  return iterate(position)->data();

}

// Insert node at specified position
void LinkedList::insertPosition(int position, int newNum) {  
  // If <= 1 insert at head
  if (position <= 1) {
    Node* newNode = new Node(newNum, this->head);    
    this->head = newNode;
  // If >= size insert at tail
  } else if (position >= this->m_size) {
    Node* newNode = new Node(newNum, nullptr);
    this->tail->next() = newNode;    
    this->tail = newNode;    
  } else {
    // Else, iterate until specified position
    Node* beforeInsert = iterate(position - 1);    
    // Insert new node and link previous and subsequent node appropriately
    Node* newNode = new Node(newNum, beforeInsert->next());
    beforeInsert->next() = newNode;
  }
  // Increment size
  this->m_size++;
}

// Returns data value at head
int LinkedList::begin() {
return head->data();
}

// Returns data value at tail
int LinkedList::end() {
return tail->data();
}

// Returns index of specific target or -1 if not found
int LinkedList::search(int target) {
  int index = 1;
  for (auto i = this->head; i != nullptr; i = i->next()) {
    if (i->data() == target) {
      return index;
    }
    index++;
  }
 return -1;
}

// Print list within square brackets separated by spaces
void LinkedList::printList() {
  std::cout << "[";
  for (auto i = this->head; i != nullptr; i = i->next()) {
    if (i == this->tail) {
      std::cout << i->data();
    } else {
      std::cout << i->data() << " ";
    }
  }
  std::cout << "]\n";
}

// Delete specified position
bool LinkedList::deletePosition(int position) {

  // Return false if position out of bounds
  if (position <= 0 || position > m_size) {
    return false;
  }

  // Handle edge case (deleting at first position)
  if (position == 1) {
    Node* newHead = this->head->next();
    delete head;
    this->head = newHead;
    this->m_size--;
    return true;
  }
  
  // To store the node prior to the deletion position
  Node* beforeDelete;
  // Iterate through list
  int count = 1;
  Node* iterator = head;
  while (count < position) {
    // Save node prior to deletion
    if (count++ == position - 1) {
        beforeDelete = iterator;
    }
    iterator = iterator->next();
  }
  // Link node prior to deletion to node after deletion
  beforeDelete->next() = iterator->next();
  // Delete specified node
  delete iterator;
  // Update tail if necessary
  if (position == m_size) {
    this->tail = beforeDelete;
  }
  // Decrement size
  this->m_size--;
  return true;
}

// Return size of list
int LinkedList::size() {
  return this->m_size;
}

// Destructor
LinkedList::~LinkedList() {
  // Call delete function
  LinkedList::deleteList();
}

// Deletes linked list from heap
void LinkedList::deleteList() { 
  Node* iterator = this->head;
  Node* tempNext;
  while (iterator != nullptr) {
    tempNext = iterator->next();
    delete iterator;
    iterator = tempNext;
  }
  this->m_size = 0;
  this->head = nullptr; 
  this->tail = nullptr;  
}