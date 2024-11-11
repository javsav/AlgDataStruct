#include "RedBlackTree.h"
#include "RedBlackTree.cpp"
#include "RBTNode.h"
#include "RBTNode.cpp"

#include <string>

int main() {
  std::vector<int> list = {1,2,4,5,6,7,8,9,10,11,12,13,14,15,16,17, 18, 19, 20, 21};
  //RedBlackTree<NodeData<int, std::string>> tree;
  RedBlackTree<int> tree;
  tree.printAsTree();
  std::cout << "\n\n";
  tree.insert(34);
  tree.printAsTree();
  std::cout << "\n\n";
  tree.insert(27);
  tree.printAsTree();
  std::cout << "\n\n";
  tree.insert(1);
  tree.printAsTree();
  std::cout << "\n\n";
  tree.insert(35);
  tree.printAsTree();
  std::cout << "\n\n"; //7,8,9,10,11,12,13,14
  tree.insert({7, 8, 9, 10, 11, 12, 13, 14});
  tree.printAsTree();
  std::cout << "\n\n";
  tree.printInOrder();
  std::cout << "\n\n";
  
  tree.remove(12);
  tree.printAsTree();
  std::cout << "\n\n";
  tree.remove(10);
  tree.printAsTree();
  std::cout << "\n\n";

  // std::string test = "a";
  // NodeData<int, std::string> datum(1, "aa");
  // tree.insert(datum);
  // NodeData<int, std::string> datum2(3, "aaa");
  // tree.insert(datum2);
// std::string test = "a";
//   for (int i = 0; i < 10; i++) {
//     test += + 'a';
//     NodeData<int, std::string> datum(i, test);
//     tree.insert(datum);
//     //tree.printAsTree();
//   }
// tree.printAsTree();
  // for (int i = 0; i < 10; i++) {
  //   //test += + 'a';
  //   //NodeData<int, std::string> datum(i, test);
  //   tree.insert(i);
  // }

  // tree.printAsTree();
  // tree.insert(11);
  // tree.printAsTree();
  // tree.insert(13);
  // std::cout << "\n";
  // tree.printAsTree();
}

//                  11B
//            6B       16B
//       2B         8B
//    1B  4B       7B  9B
// 3R 5R 10R 15R 18R 20B