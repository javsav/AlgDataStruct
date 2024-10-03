#include "Trie.h"
#include <iostream>

int main() {
  Trie Tree;

  Tree.insert("salmon");

  std::cout << Tree.search("salmon") << '\n';
  

  //char datum = pars['s' - 'a'].children['a'-'a']->data;

  //std::cout << datum << '\n';
}