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

  return current;
}

bool Trie::match(std::string word) {
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
    character++;
  }

  if (current->isLeaf) {
    return current;
  }

  return false;
  
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

void Trie::printTrie() {
  std::vector<std::string> words;
  std::string word;
  for (int i = 0; i < chars; i++) {
    if (parent.children[i] != nullptr) {      
      word += parent.children[i]->data;
      findAll(parent.children[i], word, words);
      word.pop_back();
    }
  }
  for (std::string word : words) {
    std::cout << word << ' ';
  }
  std::cout << '\n';
}

void Trie::free(TrieNode* node) {

  for (int i = 0; i < chars; i++) {
    if (node->children[i] != nullptr) {      
      free(node->children[i]);
    }
  }

  for (int i = 0; i < chars; i++) {
    TrieNode* temp = node->children[i];
    delete temp;
    node->children[i] = nullptr;
  }
  
}

void Trie::deleteTrie() {
  free(&parent);
}

Trie::~Trie() {
  free(&parent);
}