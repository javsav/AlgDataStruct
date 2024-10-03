#include "Trie.h"
#include <iostream>

Trie::Trie() {}

void Trie::insert(std::string word) {
  auto pointer = word.begin();
  TrieNode* current = new TrieNode(*pointer);
  parent.children.insert(current);
  pointer++;

  if (pointer == word.end()) {
    current->isLeaf = true;
    return;
  }

  while (pointer != word.end()) {
    TrieNode* newNode = new TrieNode(*pointer);
    current->children.insert(newNode);
    current = newNode;
    pointer++;
  }
}

bool Trie::search(std::string word) {
  auto pointer = word.begin();

  if (!parent.children.count(new TrieNode(*pointer))) {
    return false;
  }

  auto current = parent.children.find(new TrieNode(*pointer));
  pointer++;

  if (pointer == word.end()) {
    return true;
  }
  TrieNode* currentNode = *current;
  auto next = currentNode->children.find(new TrieNode(*pointer));
  while (pointer != word.end()) {    
    next = currentNode->children.find(new TrieNode(*pointer));
    
    if (next == currentNode->children.end()) {
      return false;
    }
    currentNode = *next;
    if (currentNode->isLeaf == true) {
      return true;
    }
  }

  return false; 

}

// void Trie::insert(std::string word) {
//   // check length
  
//   auto pointer = word.begin();
//   Node* parent = &parents[*pointer - 'a'];  
//   pointer++;
//   Node* child = parent->children[*pointer - 'a'];
//   child = new Node(*pointer);
//   if (pointer == word.end()) {
//     child->isLeaf = true;
//   }

//   pointer++;

//   while (pointer != word.end()) {
//     Node* newNode = new Node(*pointer);
//     child->children[*pointer - 'a'] = newNode;
//     child = newNode;
//     pointer++;
//   }

//   child->isLeaf = true;

// }

// bool Trie::search(std::string word) {

//   auto pointer = word.begin();
//   std::cout << *pointer << '\n';
//   Node* current = &parents[*pointer - 'a'];
//   std::cout << current->data;

//   pointer++;

//   while (pointer != word.end()) {
//     std::cout << current->data;
//     current = current->children[*pointer - 'a'];
//     pointer++;    
//   }
// return true;
// }