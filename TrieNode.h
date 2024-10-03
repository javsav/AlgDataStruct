#ifndef TRIENODE_H
#define TRIENODE_H

#define chars 26
#include <unordered_set>


class TrieNode {
 private:
  char data;
  TrieNode* children[chars] {{}};
  bool isLeaf = false;
  friend class Trie;
  friend class Autocomplete;
 public:
  char operator==(const TrieNode& node);
  operator char();
  TrieNode(char letter);
  TrieNode(char letter, bool isLeaf);
  TrieNode();
};

#endif //TRIENODE_H