#include "TrieNode.h"
#include <string>
class Trie {

 private:
  TrieNode parent;
  friend class Autocomplete;

 public:
  Trie();
  void insert(std::string word);
  bool search(std::string word);
  


};