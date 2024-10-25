#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "TreeNode.h"
#include <vector>
#include <initializer_list>

template <class T>
class BinarySearchTree {

 private:
  TreeNode<T> root;
  int depth;
  int size;
  void printAssist(TreeNode<T>* node);

 public:
  BinarySearchTree(T rootVal);
  BinarySearchTree(std::vector<T> list);
  void print();
  void printLeftSubtree();
  void printRightSubtree();
  void insert(T data);
  void insert(std::initializer_list<T> args);
  int getParent(T value);
  TreeNode<T>* getNode(T value);
};

#endif // BINARYSEARCHTREE_H


