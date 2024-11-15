#ifndef MAP_H
#define MAP_H
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <vector>

#include "MapNode.h"

template <typename T, typename U>
class Map {
 private:
  MapNode<T,U>* root;
  void inOrderPrint(MapNode<T,U>* node);
  void preOrderPrint(MapNode<T,U>* node);
  void postOrderPrint(MapNode<T,U>* node);
  void trav(MapNode<T,U>* node);
  MapNode<T,U>* smallestChild(MapNode<T,U>* node);
  void leftRotate(MapNode<T,U>* x);
  void rightRotate(MapNode<T,U>* x);
  void transplant(MapNode<T,U>* recipient, MapNode<T,U>* donor);
  MapNode<T,U>* search(T value);
  void fixInsert(MapNode<T,U>* k);
  void populate(MapNode<T,U>* current, std::vector<int>& list, int start, int end);
  void fixDelete(MapNode<T,U>*& node, MapNode<T,U>*& parent);
  size_t m_size = 0;

 public:
  size_t size() { return this->m_size; }
  Map();
  Map(std::vector<int> list);
  U find(T key);
  
  void printInOrder();
  void printPreOrder();
  void printPostOrder();
  void printByLevel();
  void printAsTree();
  void insert(T key);
  void insert(std::initializer_list<T> keys);
  void insert(T key, U data);
  void remove(T value);
  U operator[](T key);
};

#endif
