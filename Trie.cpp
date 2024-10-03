#include "Trie.h"
#include <iostream>

template<>
Trie<char>::Trie() {}

template<>
Trie<int>::Trie() {}

template<>
void Trie<char>::insert(std::string word) {
  auto character = word.begin();
  TrieNode<char>* current; 

  if (!parent.children[*character - 'a']) {
    current = new TrieNode<char>(*character);
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
    TrieNode<char>* newNode;

    if (!current->children[*character - 'a']) {
      newNode = new TrieNode<char>(*character);
      current->children[*character - 'a'] = newNode;
    } else {
      newNode = current->children[*character - 'a'];
    }
    
    current = newNode;
    character++;
  }
  current->isLeaf = true;
}

template<>
void Trie<int>::insert(std::string word) {
  auto character = word.begin();
  TrieNode<int>* current;

  if (!parent.children[*character - '0']) {
    current = new TrieNode<int>(*character - '0');
    parent.children[*character - '0'] = current;
  } else {
    current = parent.children[*character - '0'];
  }

  character++;

  if (character == word.end()) {
    current->isLeaf = true;
    return;
  }

  while (character != word.end()) {
    TrieNode<int>* newNode;

    if (!current->children[*character - '0']) {
      newNode = new TrieNode<int>(*character);
      current->children[*character - '0'] = newNode;
    } else {
      newNode = current->children[*character - '0'];
    }

    current = newNode;
    character++;
  }
  current->isLeaf = true;
}

template <>
void Trie<int>::insertRouter(std::string address, int routerNumber) {
  auto character = address.begin();
  TrieNode<int>* current;

  if (!parent.children[*character - '0']) {
    current = new TrieNode<int>(*character - '0');
    parent.children[*character - '0'] = current;
  } else {
    current = parent.children[*character - '0'];
  }

  character++;

  if (character == address.end()) {
    current->isLeaf = routerNumber;
    return;
  }

  while (character != address.end()) {
    TrieNode<int>* newNode;

    if (!current->children[*character - '0']) {
      newNode = new TrieNode<int>(*character);
      current->children[*character - '0'] = newNode;
    } else {
      newNode = current->children[*character - '0'];
    }

    current = newNode;
    character++;
  }
  current->isLeaf = routerNumber;
}

template<>
TrieNode<char>* Trie<char>::search(std::string word) {
  auto character = word.begin();
  if (!parent.children[*character - 'a']) {
    return nullptr;
  }

  TrieNode<char>* current = parent.children[*character - 'a'];
  character++;

  if (character == word.end()) {
    return current;
  }

  TrieNode<char>* next;

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

template<>
TrieNode<int>* Trie<int>::search(std::string word) {
  auto character = word.begin();
  if (!parent.children[*character - '0']) {
    return nullptr;
  }

  TrieNode<int>* current = parent.children[*character - '0'];
  character++;

  if (character == word.end()) {
    return current;
  }

  TrieNode<int>* next;

  while (character != word.end()) {
    next = current->children[*character - '0'];
    if (!next) {
      return nullptr;
    }
    current = next;
    character++;
  }

  return current;
}


template<>
bool Trie<char>::match(std::string word) {
  auto character = word.begin();

  if (!parent.children[*character - 'a']) {
    return false;
  }

  TrieNode<char>* current = parent.children[*character - 'a'];
  character++;

  if (character == word.end()) {
    return true;
  }

  TrieNode<char>* next;

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

template<>
bool Trie<int>::match(std::string word) {
  auto character = word.begin();

  if (!parent.children[*character - '0']) {
    return false;
  }

  TrieNode<int>* current = parent.children[*character - '0'];
  character++;

  if (character == word.end()) {
    return true;
  }

  TrieNode<int>* next;

  while (character != word.end()) {
    next = current->children[*character - '0'];
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

template <>
int Trie<int>::findNext(TrieNode<int>* current) {
  if (current->isLeaf) {
    return current->isLeaf;
  }

  for (int i = 0; i < numbers; i++) {
    if (current->children[i] != nullptr) {
      TrieNode<int>* next = current->children[i];
      return findNext(next);
      break;
    }
  }
  return 0;
}

template<>
int Trie<int>::findRouter(std::string address) {
  auto digit = address.begin();
  if (!parent.children[*digit - '0']) {
    return -1;
  }

  TrieNode<int>* current = parent.children[*digit - '0'];
  digit++;

  if (digit == address.end()) {
    return current->isLeaf;
  }

  TrieNode<int>* next;

  while (digit != address.end()) {
    next = current->children[*digit - '0'];
    if (!next) {
      break;
    }
    current = next;
    digit++;
  }
  return findNext(current);
}

template<>
void Trie<char>::findAll(TrieNode<char>* current, std::string& prefix, std::vector<std::string>& words) {
  if (current->isLeaf) {
    words.push_back(prefix);
  }

  for (int i = 0; i < chars; i++) {
    if (current->children[i] != nullptr) {
      TrieNode<char>* next = current->children[i];
      prefix += next->data;
      findAll(next, prefix, words); // Recursively search
      prefix.pop_back();            // Backtrack
    }
  }
}

template<>
void Trie<int>::findAll(TrieNode<int>* current, std::string& prefix, std::vector<std::string>& words) {
  if (current->isLeaf) {
    words.push_back(prefix);
  }

  for (int i = 0; i < numbers; i++) {
    if (current->children[i] != nullptr) {
      TrieNode<int>* next = current->children[i];
      prefix += next->data;
      findAll(next, prefix, words);  // Recursively search
      prefix.pop_back();             // Backtrack
    }
  }
}

template <>
std::vector<std::string> Trie<char>::matchPrefix(std::string prefix) {
  std::vector<std::string> matches;

  TrieNode<char>* prefixNode = search(prefix);
  if (!prefixNode) {
    return matches;
  }
  findAll(prefixNode, prefix, matches);
  return matches;
}

template<>
std::vector<std::string> Trie<int>::matchPrefix(std::string prefix) {
  std::vector<std::string> matches;

  TrieNode<int>* prefixNode = search(prefix);
  if (!prefixNode) {
    return matches;
  }
  findAll(prefixNode, prefix, matches);
  return matches;
}

template<>
void Trie<char>::printTrie() {
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

template<>
void Trie<int>::printTrie() {
  std::vector<std::string> words;
  std::string word;
  for (int i = 0; i < numbers; i++) {
    if (parent.children[i] != nullptr) {      
      word += parent.children[i]->data + '0';
      findAll(parent.children[i], word, words);
      word.pop_back();
    }
  }
  for (std::string word : words) {
    std::cout << word << ' ';
  }
  std::cout << '\n';
}

template<>
void Trie<char>::free(TrieNode<char>* node) {
  for (int i = 0; i < chars; i++) {
    if (node->children[i] != nullptr) {
      free(node->children[i]);
    }
  }

  for (int i = 0; i < chars; i++) {
    TrieNode<char>* temp = node->children[i];
    delete temp;
    node->children[i] = nullptr;
  }
}

template<>
void Trie<int>::free(TrieNode<int>* node) {

  for (int i = 0; i < numbers; i++) {
    if (node->children[i] != nullptr) {      
      free(node->children[i]);
    }
  }

  for (int i = 0; i < numbers; i++) {
    TrieNode<int>* temp = node->children[i];
    delete temp;
    node->children[i] = nullptr;
  }
  
}

template<>
void Trie<char>::deleteTrie() {
  free(&parent);
}

template<>
void Trie<int>::deleteTrie() {
  free(&parent);
}

template<>
Trie<char>::~Trie() {
  free(&parent);
}

template<>
Trie<int>::~Trie() {
  free(&parent);
}