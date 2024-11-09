#ifndef REDBLACKTREE_CPP
#define REDBLACKTREE_CPP
#include "RedBlackTree.h"
#include <iomanip>
#include <algorithm>
#include <queue>
template <typename T>
void RedBlackTree<T>::inOrderPrint(RBTNode<T>* node) {
  if (node->leftChild != nullptr) {
    inOrderPrint(node->leftChild);
  }
  std::cout << node->data << " ";
  if (node->rightChild != nullptr) {
    inOrderPrint(node->rightChild);
  }
}
template <typename T>
void RedBlackTree<T>::preOrderPrint(RBTNode<T>* node) {
  std::cout << node->data << " ";
  if (node->leftChild != nullptr) {
    preOrderPrint(node->leftChild);
  }  
  if (node->rightChild != nullptr) {
    preOrderPrint(node->rightChild);
  }
}
template <typename T>
void RedBlackTree<T>::postOrderPrint(RBTNode<T>* node) {
  if (node->leftChild != nullptr) {
    postOrderPrint(node->leftChild);
  }
  if (node->rightChild != nullptr) {
    postOrderPrint(node->rightChild);
  }
  std::cout << node->data;
  if (node->isRed) {
    std::cout << "(R)" << ' ';
  } else {
    std::cout << "(B)" << ' ';
  }
}

template <typename T>
RedBlackTree<T>::RedBlackTree(std::vector<int> list) {
  std::sort(list.begin(), list.end());

  int n = list.size() - 1;
  int end = n;  
  int start = 0;  
  int mid = (end + start) / 2;
  int rMid = (mid + 1 + end) / 2;
  int lMid = (start + mid - 1) / 2;
  //RBTNode* current = this->root;
  root = new RBTNode<T>(list[mid]);
  root->leftChild = new RBTNode<T>(list[lMid], root);
  root->rightChild = new RBTNode<T>(list[rMid], root);
  populate(root->leftChild, list, start, mid - 1);
  populate(root->rightChild, list, mid + 1, end);
}
template <typename T>
void RedBlackTree<T>::populate(RBTNode<T>* current, std::vector<int>& list, int start, int end)
{
  if (start >= end) {
    return;
  }
  int mid = (end + start) / 2;
  int rMid = mid + ((end - mid + 1) / 2);
  int lMid = start + ((mid - 1 - start) / 2);
  if ((mid == rMid)) {
    current->leftChild = new RBTNode<T>(list[lMid], current, true);
    return;
  } else if ((mid == lMid)) {
    current->rightChild = new RBTNode<T>(list[rMid], current, true);
    return;
  }
  current->leftChild = new RBTNode<T>(list[lMid], current);
  current->rightChild = new RBTNode<T>(list[rMid], current);
  populate(current->leftChild, list, start, mid - 1);
  populate(current->rightChild, list, mid + 1, end);
}
template <typename T>
void RedBlackTree<T>::printInOrder() {
  inOrderPrint(root);
  std::cout << '\n';
}
template <typename T>
void RedBlackTree<T>::printPreOrder() {
  preOrderPrint(root);
  std::cout << '\n';
}
template <typename T>
void RedBlackTree<T>::printPostOrder() {
  postOrderPrint(root);
  std::cout << '\n';
}
template <typename T>
void RedBlackTree<T>::printByLevel() {
  
  std::queue<RBTNode<T>*> nodes;

  nodes.push(root);
  RBTNode<T>* current = nullptr;
  RBTNode<T>* levelParent = root;
  while (!nodes.empty()) {
    current = nodes.front();
    while (current == nullptr) {
      std::cout << std::setw(6) << "NI " << std::setw(6);
      nodes.pop();
      if (!nodes.empty()) {
        current = nodes.front();
      } else {
        return;
      }      
    }
    
    nodes.pop();

    std::cout << std::setw(2) << current->data << std::setw(2);
    if (current->isRed) {
      std::cout << "(R)" << ' ';
    } else {
      std::cout << "(B)" << ' ';
    }
    if (current == root) {
      std::cout << "\n";
    }
    if (current == levelParent->rightChild) {
      std::cout << '\n';
      levelParent = current;
    }  
    nodes.push(current->leftChild);
    nodes.push(current->rightChild);         
  }
  std::cout << '\n';
}

template <typename T>
void RedBlackTree<T>::insert(T key) {
  if (root == nullptr) {
    root = new RBTNode<T>(key);
    return;
  }
  RBTNode<T>* current = nullptr;
  RBTNode<T>* parent = nullptr;
  if (key > root->data) {
    current = root->rightChild;
  } else if (key < root->data) {
    current = root->leftChild;
  } else {    
    return;
  }
  bool isLeft = false;
  while (current != nullptr) {
    if (key > current->data) {
      if (current->rightChild) {
      current = current->rightChild;
      } else {
        parent = current;
        current = current->rightChild;
        break;
      }
    } else if (key < current->data) {
      if (current->leftChild) {
      current = current->leftChild;
      } else {
        isLeft = true;
        parent = current;
        current = current->leftChild;
        break;
      }
    } else {
      return;
    }
    
  }
  current = new RBTNode<T>(key, parent, true);
  if (isLeft) {
    parent->leftChild = current;
  } else {
    parent->rightChild = current;
  }
  
  if (current->parent->parent == nullptr) {
    return;
  }
  
  fixInsert(current);
}

template <typename T>
void RedBlackTree<T>::leftRotate(RBTNode<T>* x) {
  RBTNode<T>* y = x->rightChild;
  x->rightChild = y->leftChild;
  if (y->leftChild != nullptr) {
    y->leftChild->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == nullptr) {
    root = y;
  } else if (x == x->parent->rightChild) {
    x->parent->rightChild = y;
  } else if (x == x->parent->leftChild) {
    x->parent->leftChild = y;
  }  
  x->parent = y;
  y->leftChild = x;
}

template <typename T>
void RedBlackTree<T>::rightRotate(RBTNode<T>* x) {
  RBTNode<T>* y = x->leftChild;
  x->leftChild = y->rightChild;
  if (y->rightChild != nullptr) {
    y->rightChild->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == nullptr) {
    root = y;
  } else if (x == x->parent->rightChild) {
    x->parent->rightChild = y;
  } else if (x == x->parent->leftChild) {
    x->parent->leftChild = y;
  }  
  x->parent = y;
  y->rightChild = x;
}

template <typename T>
void RedBlackTree<T>::fixInsert(RBTNode<T>* k) {  
  
  while (k != nullptr && k != root && k->parent != nullptr && k->parent->isRed) {    
    // If k's parent is the left subchild of its parent
    if (k->parent->parent->leftChild != nullptr && k->parent == k->parent->parent->leftChild) {      
      // Create pointer to uncle (right subchild of k's grandparent)
      RBTNode<T>* uncle = k->parent->parent->rightChild;
      // If uncle is RED
      if (uncle != nullptr && uncle->isRed) {
        // Set parent and uncle to black and grandparent to red
        k->parent->isRed = false;
        uncle->isRed = false;
        k->parent->parent->isRed = true;
        // Update k to it's grandparent
        k = k->parent->parent;
        // Else if uncle is BLACK
      } else {
        // If k is it's parent's right child
        if (k == k->parent->rightChild) {
          // Set k to its parent and left rotate
          k = k->parent;
          leftRotate(k);
        }
        // Set k's parent to BLACK and k's grandparent to RED, then right rotate k's grandparent
        k->parent->isRed = false;
        k->parent->parent->isRed = true;
        rightRotate(k->parent->parent);
      }
      // Else if k's parent is their grandparent's right child     
    } else {      
      RBTNode<T>* uncle = k->parent->parent->leftChild;
      // If uncle is red
      if (uncle != nullptr && uncle->isRed) {
        // Set parent and uncle to black and grandparent to red
        k->parent->isRed = false;
        uncle->isRed = false;
        k->parent->parent->isRed = true;
        // Set k to k's grandparent
        k = k->parent->parent;
        // Else if uncle is black
      } else {
        // If k is k's parent's left child
        if (k == k->parent->leftChild) {
          // Set k to k's parent and right rotate
          k = k->parent;
          rightRotate(k);
        }
        // Set k's parent to BLACK and k's grandparent to RED then left rotate k's grandparent
        k->parent->isRed = false;
        k->parent->parent->isRed = true;
        leftRotate(k->parent->parent);
      }
    }
  }
  // Ensure that root is black
  root->isRed = false;
}

template <typename T>
template <typename U>
inline void RedBlackTree<T>::insert(T key, U data) {}

#endif

// 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16