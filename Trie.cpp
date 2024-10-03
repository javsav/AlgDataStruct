#include "Trie.h"
#include <iostream>

Trie::Trie() {}

void Trie::insert(std::string word) {
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

bool Trie::search(std::string word) {
  auto character = word.begin();
  if (!parent.children[*character - 'a']) {
    return false;
  }

  TrieNode* current = parent.children[*character - 'a'];
  character++;

  if (character == word.end()) {
    return true;
  }

  TrieNode* next;

  while (character != word.end()) {
    next = current->children[*character - 'a'];
    if (!next) {
      return false;
    }
    current = next;
    if (current->isLeaf == true) {
      return true;
    }
    character++;
  }

  return false; 

}

