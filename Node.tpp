#ifndef NODE_TPP
#define NODE_TPP
template <typename T>
class Node {
 private:
  T data;
  Node* next;
  Node* previous;
  template <class DataType> friend class LinkedList;
 public:
  Node() : data(), next(nullptr), previous(nullptr) {}
  Node(T data) : data(data), next(nullptr), previous(nullptr) {}
  Node(T data, Node* next) : data(data), next(next), previous(nullptr) {}
  Node(T data, Node* next, Node* previous) : data(data), next(next), previous(previous) {}

};

#endif

