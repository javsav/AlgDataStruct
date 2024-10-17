#include "TreeNode.h"

template <typename T>
class RedBlackTree {

 private:
  TreeNode<T> root;
  int size;
  int height;

 public:
  TreeNode<T>* find(T data);
  void insert(T data);
  void delete(T data);
  void balance();

};


