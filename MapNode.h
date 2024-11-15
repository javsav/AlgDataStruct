#ifndef MAPNODE_H
#define MAPNODE_H
template <typename T, typename U>
class MapNode {
 private:
  T key;
  U data;
  MapNode* parent;
  MapNode* rightChild;
  MapNode* leftChild;
  bool isRed;
  template <typename keyType, typename dataType>
  friend class Map;

 public:
  MapNode(T key, MapNode<T,U>* parent, bool isRed);
  MapNode(T key, MapNode<T,U>* parent);
  MapNode(T key);
  MapNode(T key, MapNode<T, U>* parent, bool isRed, U data);
  MapNode(T key, MapNode<T, U>* parent, U data);
  MapNode(T key, U data);
};

#endif