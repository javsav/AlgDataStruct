#ifndef NODE_H
#define NODE_H

class Node {

 private:
  int m_data;
  Node* link;
  Node*& next();
  int& data();
  friend class LinkedList;

 public:
  Node(int data);
  Node(int data, Node* next);
  Node();  

};

#endif