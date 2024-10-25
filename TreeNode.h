#ifndef TREENODE_H
#define TREENODE_H
template<class T>
class TreeNode {

 public:
  T data;
  TreeNode<T>* parent;
  TreeNode<T>* leftChild;
  TreeNode<T>* rightChild;
  template<class datatype> friend class BinarySearchTree;

 public:
  TreeNode(T data, TreeNode<T>* parent, TreeNode<T>* l, TreeNode<T>* r);
  TreeNode(T data, TreeNode<T>* l, TreeNode<T>* r);
  TreeNode(T data);
  TreeNode();
  TreeNode(T data, TreeNode<T>* parent);
  void setParent(TreeNode<T>* node);
};

#endif // TREENODE_H