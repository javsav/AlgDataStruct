#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include <iostream>
#include <vector>
#include "RBTNode.h"

template<typename T>
class RedBlackTree {

 private:
  RBTNode<T>* root;
  void inOrderPrint(RBTNode<T>* node);
  void preOrderPrint(RBTNode<T>* node);
  void postOrderPrint(RBTNode<T>* node);
  void trav(RBTNode<T>* node);

 public:
  RedBlackTree();
  RedBlackTree(std::vector<int> list);
  void populate(RBTNode<T>* current, std::vector<int>& list, int start, int end);
  void printInOrder();
  void printPreOrder();
  void printPostOrder();
  void printByLevel();
  void insert(T key);
  template <typename U>
  void insert(T key, U data);
  void leftRotate(RBTNode<T>* x);
  void rightRotate(RBTNode<T>* x);
  void fixInsert(RBTNode<T>* k);
};

#endif


