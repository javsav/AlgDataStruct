#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include "Trie.h"
#include <vector>

class Autocomplete {
 private:
  Trie<char> trie;
 public:
  std::vector<std::string> getSuggestions(std::string partialWord);
  void insert(std::string word);
};

#endif // AUTOCOMPLETE_H