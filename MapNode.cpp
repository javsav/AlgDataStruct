#ifndef MAPNODE_CPP
#define MAPNODE_CPP
#include "MapNode.h"

template <typename T, typename U>
MapNode<T,U>::MapNode(T key, MapNode<T,U>* parent, bool isRed) : key(key), parent(parent), isRed(isRed), leftChild(nullptr), rightChild(nullptr) {}
template <typename T, typename U>
MapNode<T, U>::MapNode(T key, MapNode<T, U>* parent) : key(key), parent(parent), isRed(false), leftChild(nullptr), rightChild(nullptr) {}
template <typename T, typename U>
MapNode<T, U>::MapNode(T key) : key(key), parent(nullptr), isRed(false), leftChild(nullptr), rightChild(nullptr) {}

template <typename T, typename U>
MapNode<T, U>::MapNode(T key, MapNode<T, U>* parent, bool isRed, U data) : key(key), parent(parent), isRed(isRed), leftChild(nullptr), rightChild(nullptr), data(data) {}
template <typename T, typename U>
MapNode<T, U>::MapNode(T key, MapNode<T, U>* parent, U data) : key(key), parent(parent), isRed(false), leftChild(nullptr), rightChild(nullptr), data(data) {}
template <typename T, typename U>
MapNode<T, U>::MapNode(T key, U data) : key(key), parent(nullptr), isRed(false), leftChild(nullptr), rightChild(nullptr), data(data) {}

#endif
