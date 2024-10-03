#ifndef TRIENODE_H
#define TRIENODE_H

#define chars 26
#define digits 10

template<class T>
class TrieNode;

template<>
class TrieNode<char> {

 private:
  char data;
  TrieNode<char>* children[chars] {{}};
  bool isLeaf = false; 
  template<class T> friend class Trie;
  
 public:
  operator char();
  TrieNode(char letter);
  TrieNode(char letter, bool isLeaf);
  TrieNode();
  
};

template <>
class TrieNode<int> {

 private:
  int data;
  TrieNode<int>* children[digits]{{}};
  int isLeaf = false;
  template<class T> friend class Trie;

 public:
  operator int();
  TrieNode(int letter);
  TrieNode(int letter, bool isLeaf);
  TrieNode();
};

#endif //TRIENODE_H