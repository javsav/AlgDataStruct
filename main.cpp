#include "Trie.h"

#include <string>

int main() {

  Trie<int> trie;
  trie.insert("apple");
  trie.insert("application");
  trie.insert("applet");
  trie.insert("beast");
  trie.insert("beastiality");
  trie.insert("z");

  trie.printAll();

  std::vector<std::string> words = trie.search("be");

  for (auto word:words) {
    std::cout << word << ' ';
  }
  std::cout << '\n';

  std::cout << trie["sd"] << '\n';
  
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