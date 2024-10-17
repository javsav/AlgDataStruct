#include "TreeNode.h"

template <typename T>
TreeNode<T>::TreeNode(T data, TreeNode* l, TreeNode* r, bool colour) : data(data), leftChild(l), rightChild(r), isRed(colour) {}

template <typename T>
TreeNode<T>::TreeNode(T data, TreeNode* l, TreeNode* r) : TreeNode::TreeNode(data, l, r, true) {}

template <typename T>
TreeNode<T>::TreeNode(T data, bool colour) : TreeNode::TreeNode(data, nullptr, nullptr, colour) {}

template <typename T>
TreeNode<T>::TreeNode(T data) : TreeNode::TreeNode(data, nullptr, nullptr, true) {
}

template <typename T>
TreeNode<T>::TreeNode() : data(), leftChild(nullptr), rightChild(nullptr), isRed(true) {
}
