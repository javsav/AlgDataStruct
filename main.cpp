#include "RedBlackTree.h"
#include "RedBlackTree.cpp"
#include "RBTNode.h"
#include "RBTNode.cpp"

#include <string>

int main() {
  std::vector<int> list = {1,2,4,5,6,7,8,9,10,11,12,13,14,15,16,17, 18, 19, 20, 21};
  RedBlackTree<int> tree(list);
  tree.printByLevel();
  tree.printPreOrder();
  std::cout << "\n";
  tree.insert(34);
  tree.printByLevel();
  tree.printPreOrder();
  tree.insert(27);
  tree.printByLevel();
  tree.printPreOrder();
  tree.printInOrder();
  tree.insert(3);
  tree.printByLevel();
  std::cout << '\n';
  tree.printPreOrder();
  tree.printInOrder();
}

//                  11B
//            6B       16B
//       2B         8B
//    1B  4B       7B  9B
// 3R 5R 10R 15R 18R 20B