#include "Trie.h"
#include <iostream>


Trie::Trie() {}

void Trie::insert(std::string& word) {
  auto character = word.begin();
  TrieNode* current = new TrieNode(*character);
  parent.children[*character - 'a'] = current;
  character++;

  if (character == word.end()) {
    current->isLeaf = true;
    return;
  }

  while (character != word.end()) {
    TrieNode* newNode = new TrieNode(*character);
    current->children[*character - 'a'] = newNode;
    current = newNode;
    character++;
  }
  current->isLeaf = true;
}

TrieNode* Trie::search(std::string word) {
  auto character = word.begin();
  if (!parent.children[*character - 'a']) {
    return nullptr;
  }

  TrieNode* current = parent.children[*character - 'a'];
  character++;

  if (character == word.end()) {
    return current;
  }

  TrieNode* next;

  while (character != word.end()) {
    next = current->children[*character - 'a'];
    if (!next) {
      return nullptr;
    }
    current = next;
    if (current->isLeaf == true) {
      return current;
    }
    character++;
  }

  return nullptr; 

}

std::vector<std::string> Trie::matchPrefix(std::string prefix) {
  std::vector<std::string> matches;

  
}
