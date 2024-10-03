#ifndef TRIE_H
#define TRIE_H

#include "TrieNode.h"
#include <string>
#include <vector>

class Trie {

 private:
  TrieNode parent;

 public:
  Trie();
  void printTrie();
  void insert(std::string word);
  TrieNode* search(std::string word);
  bool match(std::string word);
  std::vector<std::string> matchPrefix(std::string prefix);
  void findAll(TrieNode* current, std::string& prefix, std::vector<std::string>& words);
  void free(TrieNode* node);
  void deleteTrie();
  ~Trie();
};

#endif //TRIE_H