#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include <iostream>
#include <vector>
#include <cstddef>
#include <initializer_list>
#include "RBTNode.h"

template<typename T>
class RedBlackTree {

 private:
  RBTNode<T>* root;
  void inOrderPrint(RBTNode<T>* node);
  void preOrderPrint(RBTNode<T>* node);
  void postOrderPrint(RBTNode<T>* node);
  void trav(RBTNode<T>* node);
  RBTNode<T>* smallestChild(RBTNode<T>* node);
  void leftRotate(RBTNode<T>* x);
  void rightRotate(RBTNode<T>* x);
  void transplant(RBTNode<T>* recipient, RBTNode<T>* donor);
  RBTNode<T>* search(T value);
  void fixInsert(RBTNode<T>* k);
  void populate(RBTNode<T>* current, std::vector<int>& list, int start, int end);
  void fixDelete(RBTNode<T>* node);
  size_t m_size = 0;

 public:
  size_t size() {return this->m_size;}
  RedBlackTree();
  RedBlackTree(std::vector<int> list);
  
  void printInOrder();
  void printPreOrder();
  void printPostOrder();
  void printByLevel();
  void printAsTree();
  void insert(T key);
  void insert(std::initializer_list<T> keys);
  template <typename U>
  void insert(T key, U data);  
  void remove(T value);
 
};

#endif


