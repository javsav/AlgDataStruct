#include "Trie.h"
#include <iostream>

int main() {
  Trie Tree;

  Tree.insert("salmon");

  std::cout << Tree.search("salmon") << '\n';
  std::cout << Tree.search("beef") << '\n';
  Tree.insert("beef");
  std::cout << Tree.search("beef") << '\n';

  //char datum = pars['s' - 'a'].children['a'-'a']->data;

  //std::cout << datum << '\n';
}