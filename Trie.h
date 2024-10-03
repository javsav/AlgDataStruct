#include "TrieNode.h"
#include <string>
class Trie {

 private:
  TrieNode parent;

 public:
  Trie();
  void insert(std::string word);
  bool search(std::string word);
  


};