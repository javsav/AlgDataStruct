#ifndef TRIE_H
#define TRIE_H
#include <iostream>
#include <vector>
#include <cstddef>
#include <initializer_list>
#include "TrieNode.h"

template<typename T>
class Trie {

 private:
  TrieNode<T>* root;
  void printer(TrieNode<T>* node, std::string& cur);
  void searcher(TrieNode<T>* node, std::string& cur, std::vector<std::string>& res);

 public:
  Trie();
  void insert(std::string word);
  void printAll();
  std::vector<std::string> search(const char* chs);
  T operator[](const char* chs);
 
};

#endif

template <typename T>
inline void Trie<T>::printer(TrieNode<T>* node, std::string& cur) {
  if (node->data != std::numeric_limits<T>::min()) {
    std::cout << cur << "\n";    
  }
  for (int i = 0; i < 26; i++) {
    if (node->letters[i] != nullptr) {
      cur += 'a' + i;
      printer(node->letters[i], cur);
      cur.pop_back();
    }    
  }
}

template<typename T>
void Trie<T>::searcher(TrieNode<T>* node, std::string& cur, std::vector<std::string>& res)
{
  if (node->data != std::numeric_limits<T>::min()) {
    res.push_back(cur);
  }
  for (int i = 0; i < 26; i++) {
    if (node->letters[i] != nullptr) {
      cur += 'a' + i;
      searcher(node->letters[i], cur, res);
      cur.pop_back();
    }
  }
}

template <typename T>
inline Trie<T>::Trie() {
  root = new TrieNode<T>;
}

template <typename T>
void Trie<T>::insert(std::string word) {
  int n = word.size();
  int i = 0;
  TrieNode<T>* current = root;
  while (i < n) {
    if (i == n - 1) { 
      if (!current->letters[word[i] - 'a']) {
        if (word[i] - 'a' < 26) {
          current->letters[word[i] - 'a'] = new TrieNode<T>;
        } else {
          return;
        }        
      }      
      current = current->letters[word[i] - 'a'];
      current->data = std::numeric_limits<T>::max();      
      return;
    }
    if (!current->letters[word[i] - 'a']) {
      if (word[i] - 'a' < 26) {
        current->letters[word[i] - 'a'] = new TrieNode<T>;
      } else {
        return;
      }
    }    
    current = current->letters[word[i] - 'a'];
    i++;
  }
}

template <typename T>
inline void Trie<T>::printAll() {
  TrieNode<T>* current = root;
  std::string word = "";
  printer(current, word);
}

template <typename T>
std::vector<std::string> Trie<T>::search(const char* chs) {
  int i = 0;
  std::vector<std::string> res;
  TrieNode<T>* current = root;
  while (chs[i] != '\0') {
    if (current->letters[chs[i] - 'a']) {
      current = current->letters[chs[i] - 'a'];
    } else {
      return res;
    }
    i++;
  }
  std::string cur = chs;
  searcher(current, cur, res);
  return res;
}

template <typename T>
inline T Trie<T>::operator[](const char* chs) {
  int i = 0;
  TrieNode<T>* current = root;
  while (chs[i] != '\0') {
    if (current->letters[chs[i] - 'a']) {
      current = current->letters[chs[i] - 'a'];
    } else {
      std::cout << "Word not in Trie";
      return -1;
    }
    i++;
  }
  if (current->data != std::numeric_limits<T>::min()) {
    return current->data;
  } else {
    std::cout << "Word not in Trie";
    return -1;
  }
}
