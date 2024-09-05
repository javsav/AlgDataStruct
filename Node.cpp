#include "Node.h"

Node::Node(int data) : data(data) {}

Node::Node() : Node(0) {}

void Node::setData(int data) {
  this->data = data;
}

void Node::setNext(Node* next) {
  this->next = next;
}

int Node::getData() {
  return this->data;
}

Node* Node::getNext() {
  return this->next;
}