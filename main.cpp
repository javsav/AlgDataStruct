#include "Trie.h"
#include <iostream>

int main() {
  Trie Tree;
  Tree.insert("salmon");

  Tree.insert("bead");

  Tree.insert("beer");

  Tree.insert("bear");

  Tree.insert("beautiful");

  Tree.insert("beam");

  std::cout << Tree.search("bead") << '\n';
  std::cout << Tree.search("beer") << '\n';
  std::cout << Tree.search("bear") << '\n';
  std::cout << Tree.search("beautiful") << '\n';
  std::cout << Tree.search("beam") << '\n';

  std::vector<std::string> matches = Tree.matchPrefix("be");

  for (auto word = matches.begin(); word != matches.end(); ++word) {
    std::cout << *word << ' ';
  }
  std::cout << '\n';

 
}