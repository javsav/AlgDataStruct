#include "RedBlackTree.h"
#include "RedBlackTree.cpp"
#include "RBTNode.h"
#include "RBTNode.cpp"

#include <string>

int main() {
  std::vector<int> list = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17, 18, 19, 20, 21};
  RedBlackTree<int> tree(list);
  tree.printByLevel();
  tree.insert(34);
  tree.printByLevel();
  tree.printInOrder();
}