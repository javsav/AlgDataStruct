#include "Map.h"
#include "Map.cpp"
#include "MapNode.h"
#include "MapNode.cpp"

#include <string>


int main() {

  Map<std::string, int> lemap;

  lemap.insert("aids",2);
  lemap.insert("boo", 7);
  lemap.insert("anus", 1);

  lemap.printAsTree();

  std::cout << lemap.find("boo") << "\n";

  // std::vector<int> list = {-2, -3, -1, -5};
  // //RedBlackTree<NodeData<int, std::string>> tree;
  // RedBlackTree<int> tree;

  // tree.insert({1,2,3,4,5,6,7,8,9,10,13});
  // tree.printAsTree();
  // std::cout << "\n\n";
  // tree.insert(14);
  // tree.printAsTree();
  // std::cout << "\n\n";
  // tree.remove(3);
  // tree.printAsTree();
  // std::cout << "\n\n";
  // tree.remove(14);
  // tree.printAsTree();
  // std::cout << "\n\n";
  // tree.remove(8);
  // tree.printAsTree();
  // std::cout << "\n\n";


}

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
   

//                  11B
//            6B       16B
//       2B         8B
//    1B  4B       7B  9B
// 3R 5R 10R 15R 18R 20B