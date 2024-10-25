#include "BinarySearchTree.h"
#include <iostream>



template <class T>
BinarySearchTree<T>::BinarySearchTree(T rootVal) {
  this->root = TreeNode<T>(rootVal);
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(std::vector<T> list) {

  auto i = list.begin();
  this->root = TreeNode<T>(*i);
  TreeNode<T>* current = &root;
  i++;

  while (i != list.end()) {
    while (current != nullptr) {      
      if (*i > current->data) {
        if (current->rightChild == nullptr) {
          current->rightChild = new TreeNode<T>(*i, current);          
          break;
        } else {
          current = current->rightChild;
        }
      } else {
        if (current->leftChild == nullptr) {
          current->leftChild = new TreeNode<T>(*i, current);          
          break;
        } else {
          current = current->leftChild;
        }
      }
    }    
    i++;
    current = &root;
  }
}

template <class T>
void BinarySearchTree<T>::print() {
  TreeNode<T>* current = &root;
  printAssist(current);
  std::cout << '\n';  
}

template <class T>
void BinarySearchTree<T>::printLeftSubtree() {
  printAssist(root.leftChild);
  std::cout << '\n';
}

template <class T>
void BinarySearchTree<T>::printRightSubtree() {
  printAssist(root.rightChild);
  std::cout << '\n';
}

template <class T>
void BinarySearchTree<T>::printAssist(TreeNode<T>* node) {
  if (node == nullptr) {
    return;
  }
  std::cout << node->data << ' ';
  printAssist(node->leftChild);
  printAssist(node->rightChild);  
}

template <class T>
void BinarySearchTree<T>::insert(T data) {
  TreeNode<T>* current = &root;

  while (current != nullptr) {
    if (data > current->data) {
      if (current->rightChild == nullptr) {
        current->rightChild = new TreeNode<T>(data, current);       
        break;
      } else {
        current = current->rightChild;
      }
    } else {
      if (current->leftChild == nullptr) {
        current->leftChild = new TreeNode<T>(data, current);
        break;
      } else {
        current = current->leftChild;
      }
    }
  }
}

template <class T>
void BinarySearchTree<T>::insert(std::initializer_list<T> args) {
  
  auto i = args.begin();
  if (!root.leftChild && !root.rightChild) {
    this->root = TreeNode<T>(*i);    
    i++;
  }  
  TreeNode<T>* current = &root;  

  while (i != args.end()) {
    while (current != nullptr) {
      if (*i > current->data) {
        if (current->rightChild == nullptr) {
          current->rightChild = new TreeNode<T>(*i, current);
          break;
        } else {
          current = current->rightChild;
        }
      } else {
        if (current->leftChild == nullptr) {
          current->leftChild = new TreeNode<T>(*i, current);
          break;
        } else {
          current = current->leftChild;
        }
      }
    }
    i++;
    current = &root;
  }
}

template <class T>
int BinarySearchTree<T>::getParent(T value) {
  
  TreeNode<T>* current = &root;

  if (root.leftChild==nullptr && root.rightChild==nullptr) {
    return -1;
  }

  while (current != nullptr) {
    if (value > current->data) {
      if (current->rightChild == nullptr) {
        return -1;
      } else {
        current = current->rightChild;
      } 
      } else if (value < current->data) {
        if (current->leftChild == nullptr) {
          return -1;
        } else {
          current = current->leftChild;
        }
      } else if (value == current->data) {
        if (current->parent == nullptr) {
          return -1;
        } else {
          return current->parent->data;
        }
      }
    }
    return 0;
  }

  template <class T>
  TreeNode<T>* BinarySearchTree<T>::getNode(T value) {
    TreeNode<T>* current = &root;

    if (root.leftChild == nullptr && root.rightChild == nullptr) {
      return nullptr;
    }

    while (current != nullptr) {
      if (value > current->data) {
        if (current->rightChild == nullptr) {
          return nullptr;
        } else {
          current = current->rightChild;
        }
      } else if (value < current->data) {
        if (current->leftChild == nullptr) {
          return nullptr;
        } else {
          current = current->leftChild;
        }
      } else if (value == current->data) {
        return current;
      }
    }
    
    return nullptr;
  }

template <class T>
void BinarySearchTree<T>::deleteNode(T value) {
  TreeNode<T>* delNode = getNode(value);

  if (delNode->leftChild == nullptr && delNode->rightChild == nullptr) {
    
  }
}
