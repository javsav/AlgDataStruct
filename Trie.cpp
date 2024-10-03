#include "Trie.h"
#include <iostream>


Trie::Trie() {}

void Trie::insert(std::string word) {
  auto character = word.begin();
  TrieNode* current; 

  if (!parent.children[*character - 'a']) {
    current = new TrieNode(*character);
    parent.children[*character - 'a'] = current;
  } else {
    current = parent.children[*character - 'a'];
  }
  
  character++;

  if (character == word.end()) {
    current->isLeaf = true;
    return;
  }

  while (character != word.end()) {
    TrieNode* newNode;

    if (!current->children[*character - 'a']) {
      newNode = new TrieNode(*character);
      current->children[*character - 'a'] = newNode;
    } else {
      newNode = current->children[*character - 'a'];
    }
    
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
    character++;
  }

  if (current->isLeaf == true) {
    return current;
  }

  return current; 

}

std::vector<std::string> Trie::matchPrefix(std::string prefix) {
  std::vector<std::string> matches;

  TrieNode* prefixNode = search(prefix);
  if (!prefixNode) {
    return matches;
  }
  findAll(prefixNode, prefix, matches);
  return matches;  
}

void Trie::findAll(TrieNode* current, std::string& prefix, std::vector<std::string>& words) {
  if (current->isLeaf) {
    words.push_back(prefix);
  }

  for (int i = 0; i < chars; i++) {
    if (current->children[i] != nullptr) {
      TrieNode* next = current->children[i];
      prefix += next->data;
      findAll(next, prefix, words); // Recursively search
      prefix.pop_back(); // Backtrack
    }
  }
}
