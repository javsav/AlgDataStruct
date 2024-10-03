#include "Trie.h"
#include <iostream>

int main() {
  Trie<char> Tree;
  Tree.insert("salmon");

  Tree.insert("bead");

  Tree.insert("beer");

  Tree.insert("bear");

  Tree.insert("beautiful");

  Tree.insert("beam");

  std::vector<std::string> matches = Tree.matchPrefix("be");

  for (auto word = matches.begin(); word != matches.end(); ++word) {
    std::cout << *word << ' ';
  }
  std::cout << '\n';


  
  matches.clear();
  matches = Tree.matchPrefix("b");

  for (auto word = matches.begin(); word != matches.end(); ++word) {
    std::cout << *word << ' ';
  }
  std::cout << '\n';

  Tree.insert("fall");

  Tree.insert("fail");

  Tree.insert("full");

  Tree.insert("fool");

  Tree.insert("fell");

  Tree.insert("foul");

  matches = Tree.matchPrefix("f");

  for (auto word = matches.begin(); word != matches.end(); ++word) {
    std::cout << *word << ' ';
  }
  std::cout << '\n';

  Tree.printTrie();

  Tree.deleteTrie();

  Tree.printTrie();

  Trie<int> numTree;

  numTree.insertRouter("1100110111", 1);
  numTree.insertRouter("110011011", 2);
  numTree.insertRouter("11001101", 3);

  numTree.printTrie();

  int router = numTree.findRouter("1100110113");

  std::cout << "router number: " << router << '\n';

  // std::vector<std::string> nums = numTree.matchPrefix("19");

  // for (auto num:nums) {
  //   std::cout << num << ' ';
  // }
  // std::cout << '\n';
}