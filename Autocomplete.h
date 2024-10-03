#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include "Trie.h"
#include <vector>

class Autocomplete {
 private:
 Trie trie;
 public:
  std::vector<std::string> getSuggestions(std::string partialWord);
  void insert(std::string word);
};

#endif // AUTOCOMPLETE_H