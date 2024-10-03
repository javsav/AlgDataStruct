#include "Trie.h"
#include <iostream>

int main() {
  Trie Tree;
  std::string insert = "salmon";
  Tree.insert(insert);

  std::cout << Tree.search("salmon") << '\n';
  std::cout << Tree.search("beef") << '\n';
  insert = "beef";
  Tree.insert(insert);
  std::cout << Tree.search("beef") << '\n';

  //char datum = pars['s' - 'a'].children['a'-'a']->data;

  //std::cout << datum << '\n';
}