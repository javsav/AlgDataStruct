#ifndef TRIE_H
#define TRIE_H

#include "TrieNode.h"
#include <string>
#include <vector>

template<class T>
class Trie {

 private:
  TrieNode<T> parent;

 public:
  Trie();
  void printTrie();
  void insert(std::string word);
  void insertRouter(std::string address, int routerNumber);
  int findRouter(std::string address);
  int findNext(TrieNode<T>* current);
  TrieNode<T>* search(std::string word);
  bool match(std::string word);
  std::vector<std::string> matchPrefix(std::string prefix);
  void findAll(TrieNode<T>* current, std::string& prefix, std::vector<std::string>& words);
  void free(TrieNode<T>* node);  
  void deleteTrie();
  ~Trie();
};

#endif //TRIE_H