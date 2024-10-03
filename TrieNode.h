#ifndef TRIENODE_H
#define TRIENODE_H

#define chars 26

template<class T>
class TrieNode {
 public:
  T data;
  TrieNode<T>* children[chars] {{}};
  int isLeaf = false;  
  //friend class Trie;
 public:
  operator char();
  TrieNode(T letter);
  TrieNode(T letter, bool isLeaf);
  TrieNode();
};

#endif //TRIENODE_H