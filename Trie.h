#ifndef TRIE_H
#define TRIE_H

#include "TrieNode.h"
#include <string>
#include <vector>

class Trie {

 private:
  TrieNode parent;
  friend class Autocomplete;

 public:
  Trie();
  void insert(std::string& word);
  TrieNode* search(std::string word);
  std::vector<std::string> matchPrefix(std::string prefix);
};

#endif //TRIE_H