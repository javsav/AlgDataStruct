#ifndef RBTNODE_H
#define RBTNODE_H
template<typename T>
class RBTNode {
 private:
  T data;  
  RBTNode* parent;
  RBTNode* rightChild;
  RBTNode* leftChild;
  bool isRed;
  template <typename dataType> friend class RedBlackTree;
 public:
  RBTNode(T data, RBTNode<T>* parent, bool isRed);
  RBTNode(T data, RBTNode<T>* parent);
  RBTNode(T data);
};

template<typename T, typename U>
struct NodeData {
  T key;
  U data;
  NodeData(T val) : key(val), data() {}
  NodeData(T key, U data) : key(key), data(data) {}
  NodeData& operator=(T value) {
      key = value;  // Assign to key by default
      return *this;
    }
    NodeData& operator=(NodeData& value) {
      key = value->key;  // Assign to key by default
      return *this;
    }
    bool operator<(T value) {
      return key < value;
    }
    bool operator<(NodeData& value) {
      return this->key < value.key;
      
    }
    bool operator>(T value) {
      return this->key > value;
    }

    bool operator>(NodeData& value) {
     return this->key > value.key;
    }
    bool operator==(T value) {
      return value == key;
    }
    bool operator==(NodeData& value) {
      if (value.key == this->key) {
        return true;
      } else {
        return false;
      }
    }
  friend std::ostream& operator<<(std::ostream& os, const NodeData& obj) {    
    os << obj.key << ":" << obj.data;
    return os;
  }
};
#endif