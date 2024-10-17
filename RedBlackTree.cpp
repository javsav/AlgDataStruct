#include "RedBlackTree.h"
#include "TreeNode.h"

template <typename T>
TreeNode<T>* RedBlackTree<T>::find(T data) {

  TreeNode<T>* iterator = &root;

  while (iterator != nullptr) {
    if (iterator->data == data) {
      break;
    }
    
    if (data > iterator->data) {
      iterator = iterator->rightChild;
    } else {
      iterator = iterator->leftChild;
    }

  }

  if (iterator->data == data) {
    return iterator;
  } else {
    return nullptr;
  }
}

template <typename T>
void RedBlackTree<T>::insert(T data) {
  
}