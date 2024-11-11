#ifndef TRIENODE_H
#define TRIENODE_H
#include <limits>
#include <string>
template<typename T>
class TrieNode {
 private:
  TrieNode* letters[26] {{}};  
  T data = std::numeric_limits<T>::min();    
  template <typename dataType> friend class Trie;
 public:
  TrieNode(char ch, T data);
  TrieNode();
};

template <typename T>
inline TrieNode<T>::TrieNode(char ch, T data) {
  for (int i = 0; i < 26; i++) {    
    if (i == ch - 'a') {
      letters[i] = new TrieNode<T>;
    } else {
      letters[i] = nullptr;
    }
  }
  this->data = data;
}

template <typename T>
inline TrieNode<T>::TrieNode() {
  for (int i = 0; i < 26; i++) {
    letters[i] = nullptr;
  }
  data = std::numeric_limits<T>::min();
}

#endif