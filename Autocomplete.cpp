#include "Autocomplete.h"

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord) {
  return Trie.matchPrefix(partialWord);
}

void Autocomplete::insert(std::string word) {
  Trie.insert(word);
}