#ifndef TRIENODE_H
#define TRIENODE_H

#define chars 26


class TrieNode {
 private:
  char data;
  TrieNode* children[chars] {{}};
  bool isLeaf = false;  
  friend class Trie;
 public:
  operator char();
  TrieNode(char letter);
  TrieNode(char letter, bool isLeaf);
  TrieNode();
};

#endif //TRIENODE_H