#include "TrieNode.h"

TrieNode<char>::TrieNode(char letter, bool isLeaf) : data(letter), isLeaf(isLeaf) {}

TrieNode<int>::TrieNode(int letter, bool isLeaf) : data(letter), isLeaf(isLeaf) {}

TrieNode<char>::TrieNode(char letter) : TrieNode::TrieNode(letter, false) {}

TrieNode<int>::TrieNode(int letter) : TrieNode::TrieNode(letter, false) {}

TrieNode<char>::TrieNode() : TrieNode::TrieNode('.', false) {}

TrieNode<int>::TrieNode() : TrieNode::TrieNode('.', false) {}

TrieNode<char>::operator char() {
  return this->data;
}

TrieNode<int>::operator int() {
  return this->data;
}
