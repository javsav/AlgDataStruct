#include "Node.h"

Node::Node(int data) : m_data(data) {}

Node::Node(int data, Node* next) : m_data(data), link(next) {}

Node::Node() : Node(0, nullptr) {}

Node*& Node::next() {
  return this->link;
}

int& Node::data() {
  return this->m_data;
}

