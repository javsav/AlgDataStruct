#include "TreeNode.h"

template <class T>
TreeNode<T>::TreeNode(T data, TreeNode* parent, TreeNode* l, TreeNode* r) : data(data), parent(parent), leftChild(l), rightChild(r) {
}

template <class T>
TreeNode<T>::TreeNode(T data, TreeNode* l, TreeNode* r) : data(data), leftChild(l), rightChild(r), parent(nullptr) {
}

template <class T>
TreeNode<T>::TreeNode(T data) : data(data), leftChild(nullptr), rightChild(nullptr), parent(nullptr) {
}

template <class T>
TreeNode<T>::TreeNode() : data(), leftChild(nullptr), rightChild(nullptr), parent(nullptr) {
}

template <class T>
TreeNode<T>::TreeNode(T data, TreeNode<T>* parent) : data(data), parent(parent) {}

template <class T>
void TreeNode<T>::setParent(TreeNode<T>* node) {
  this->parent = node;
}
