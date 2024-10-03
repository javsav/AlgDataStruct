#include "TrieNode.h"

TrieNode::TrieNode(char letter, bool isLeaf) : data(letter), isLeaf(isLeaf) {
  for (int i = 0; i < chars; i++) {
    children[i] = nullptr;
  }
}

TrieNode::TrieNode(char letter) : TrieNode::TrieNode(letter, false) {}

TrieNode::TrieNode() : TrieNode::TrieNode('.', false) {}

char TrieNode::operator==(const TrieNode& node) {
  return this->data == node.data;
}

TrieNode::operator char() {
  return this->data;
}
