#ifndef RBTNODE_CPP
#define RBTNODE_CPP
#include "RBTNode.h"

template<typename T>
RBTNode<T>::RBTNode(T data, RBTNode<T>* parent, bool isRed) : data(data), parent(parent), isRed(isRed), leftChild(nullptr), rightChild(nullptr) {}
template<typename T>
RBTNode<T>::RBTNode(T data, RBTNode<T>* parent) : data(data), parent(parent), isRed(false), leftChild(nullptr), rightChild(nullptr) {}
template<typename T>
RBTNode<T>::RBTNode(T data): data(data), parent(nullptr), isRed(false), leftChild(nullptr), rightChild(nullptr) {}

#endif
