#include "TrieNode.h"

TrieNode::TrieNode(char letter, bool isLeaf) : data(letter), isLeaf(isLeaf) {}

TrieNode::TrieNode(char letter) : TrieNode::TrieNode(letter, false) {}

TrieNode::TrieNode() : TrieNode::TrieNode('.', false) {}

TrieNode::operator char() {
  return this->data;
}
