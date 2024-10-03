#include "TrieNode.h"

template<>
TrieNode<char>::TrieNode(char letter, bool isLeaf) : data(letter), isLeaf(isLeaf) {}

template<>
TrieNode<int>::TrieNode(int letter, bool isLeaf) : data(letter), isLeaf(isLeaf) {}

template<>
TrieNode<char>::TrieNode(char letter) : TrieNode::TrieNode(letter, false) {}

template<>
TrieNode<int>::TrieNode(int letter) : TrieNode::TrieNode(letter, false) {}

template<>
TrieNode<char>::TrieNode() : TrieNode::TrieNode('.', false) {}

template<>
TrieNode<int>::TrieNode() : TrieNode::TrieNode('.', false) {}

template<>
TrieNode<int>::operator char() {
  return this->data;
}
