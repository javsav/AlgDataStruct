#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"
#include "TreeNode.cpp"
#include <vector>

int main() {
  

  std::vector<int> test = {5, 4, 3, 8, 32 ,7, 2, 4, 5, 7, 2, 3, 9, 7, 19, 22, 1};
  BinarySearchTree<int> tree(test);
  tree.printLeftSubtree();
  tree.printRightSubtree();
  tree.insert(2);
  // tree.printRightSubtree();
  tree.printLeftSubtree();
  tree.insert(6);
  tree.printRightSubtree();
  tree.insert(6);
  tree.printRightSubtree();

  tree.insert({2,3,7,12,18,2,4});
  tree.printLeftSubtree();
  tree.printRightSubtree();
  std::cout << tree.getParent(4) << '\n';
  TreeNode<int>* node = tree.getNode(4);
  TreeNode<int>* par = node->parent;
  std::cout << par->data << '\n';
  
}