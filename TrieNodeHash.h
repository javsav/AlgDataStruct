#ifndef TRIENODEHASH_H
#define TRIENODEHASH_H

#include "TrieNode.h"
#include <cstddef>
#include <memory>

struct TrieNodeHash {
  size_t operator()(const TrieNode* &TrieNode) {    
    return std::hash<char>{}(TrieNode->data);  
  }


};

#endif //TRIENODEHASH_H