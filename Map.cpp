#ifndef MAP_CPP
#define MAP_CPP
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>

#include "Map.h"

template <typename T, typename U>
void Map<T,U>::inOrderPrint(MapNode<T,U>* node) {
  if (node->leftChild != nullptr) {
    inOrderPrint(node->leftChild);
  }
  std::cout << node->key << " ";
  if (node->rightChild != nullptr) {
    inOrderPrint(node->rightChild);
  }
}
template <typename T, typename U>
void Map<T,U>::preOrderPrint(MapNode<T,U>* node) {
  std::cout << node->key << " ";
  if (node->leftChild != nullptr) {
    preOrderPrint(node->leftChild);
  }
  if (node->rightChild != nullptr) {
    preOrderPrint(node->rightChild);
  }
}
template <typename T, typename U>
void Map<T,U>::postOrderPrint(MapNode<T,U>* node) {
  if (node->leftChild != nullptr) {
    postOrderPrint(node->leftChild);
  }
  if (node->rightChild != nullptr) {
    postOrderPrint(node->rightChild);
  }
  std::cout << node->key;
  if (node->isRed) {
    std::cout << "(R)" << ' ';
  } else {
    std::cout << "(B)" << ' ';
  }
}

template <typename T, typename U>
MapNode<T,U>* Map<T,U>::smallestChild(MapNode<T,U>* node) {
  MapNode<T,U>* current = node;

  while (current->leftChild != nullptr) {
    current = current->leftChild;
  }
  return current;
}

template <typename T, typename U>
Map<T,U>::Map() {
  root = nullptr;
}

template <typename T, typename U>
Map<T,U>::Map(std::vector<int> list) {
  std::sort(list.begin(), list.end());

  int n = list.size() - 1;
  int end = n;
  int start = 0;
  int mid = (end + start) / 2;
  int rMid = (mid + 1 + end) / 2;
  int lMid = (start + mid - 1) / 2;

  root = new MapNode<T,U>(list[mid]);
  m_size++;
  root->leftChild = new MapNode<T,U>(list[lMid], root);
  m_size++;
  root->rightChild = new MapNode<T,U>(list[rMid], root);
  m_size++;
  populate(root->leftChild, list, start, mid - 1);
  populate(root->rightChild, list, mid + 1, end);
}
template <typename T, typename U>
U Map<T, U>::find(T key) {
  MapNode<T,U>* current = search(key);

  if (current) {
    return current->data;
  } else {
    return U();
  }
}

template <typename T, typename U>
void Map<T,U>::populate(MapNode<T,U>* current, std::vector<int>& list, int start, int end) {
  if (start >= end) {
    return;
  }
  int mid = (end + start) / 2;
  int rMid = mid + ((end - mid + 1) / 2);
  int lMid = start + ((mid - 1 - start) / 2);
  if ((mid == rMid)) {
    current->leftChild = new MapNode<T,U>(list[lMid], current, true);
    m_size++;
    return;
  } else if ((mid == lMid)) {
    current->rightChild = new MapNode<T,U>(list[rMid], current, true);
    m_size++;
    return;
  }
  current->leftChild = new MapNode<T,U>(list[lMid], current);
  m_size++;
  current->rightChild = new MapNode<T,U>(list[rMid], current);
  m_size++;
  populate(current->leftChild, list, start, mid - 1);
  populate(current->rightChild, list, mid + 1, end);
}
template <typename T, typename U>
void Map<T,U>::fixDelete(MapNode<T,U>*& node, MapNode<T,U>*& parent) {
  MapNode<T,U>* sibling = nullptr;
  MapNode<T,U>* current = node;

  while (current != root) {
    if (current) {
      if (current->isRed) {
        break;
      }
    }
    if (parent && (current == parent->leftChild)) {
      sibling = parent->rightChild;
      if (sibling != nullptr && sibling->isRed) {
        sibling->isRed = false;
        parent->isRed = true;
        leftRotate(parent);
        sibling = parent->rightChild;
      }
      if (sibling != nullptr && (!sibling->leftChild || !sibling->leftChild->isRed) && (!sibling->rightChild || !sibling->rightChild->isRed)) {
        sibling->isRed = true;
        current = parent;
        parent = current->parent;
      } else {
        if (sibling != nullptr && (!sibling->rightChild || !sibling->rightChild->isRed)) {
          if (sibling->leftChild) {
            sibling->leftChild->isRed = false;
          }
          sibling->isRed = true;
          rightRotate(sibling);
          if (parent) {
            sibling = parent->rightChild;
          }
        }
        if (parent) {
          sibling->isRed = parent->isRed;
          parent->isRed = false;
        }
        if (sibling && sibling->rightChild) {
          sibling->rightChild->isRed = false;
        }
        leftRotate(parent);
        current = root;
        parent = nullptr;
      }
    } else if (parent) {
      sibling = parent->leftChild;
      if (sibling != nullptr && sibling->isRed) {
        sibling->isRed = false;
        parent->isRed = true;
        rightRotate(parent);
        sibling = parent->leftChild;
      }
      if (sibling && (!sibling->leftChild || !sibling->leftChild->isRed) &&
          (!sibling->rightChild || !sibling->rightChild->isRed)) {
        sibling->isRed = true;
        current = parent;
        parent = parent->parent;
      } else {
        if (sibling && (!sibling->leftChild || !sibling->rightChild->isRed)) {
          if (sibling->rightChild) {
            sibling->rightChild->isRed = false;
          }
          sibling->isRed = true;
          leftRotate(sibling);
          sibling = parent->leftChild;
        }
        sibling->isRed = parent->isRed;
        parent->isRed = false;
        if (sibling && sibling->leftChild) {
          sibling->leftChild->isRed = false;
        }
        rightRotate(parent);
        current = root;
        parent = nullptr;
      }
    }
  }
  if (current) {
    current->isRed = false;
  }
}
template <typename T, typename U>
void Map<T,U>::printInOrder() {
  inOrderPrint(root);
  std::cout << '\n';
}
template <typename T, typename U>
void Map<T,U>::printPreOrder() {
  preOrderPrint(root);
  std::cout << '\n';
}
template <typename T, typename U>
void Map<T,U>::printPostOrder() {
  postOrderPrint(root);
  std::cout << '\n';
}
template <typename T, typename U>
void Map<T,U>::printByLevel() {
  std::queue<MapNode<T,U>*> nodes;

  nodes.push(root);
  MapNode<T,U>* current = nullptr;
  MapNode<T,U>* levelParent = root;
  while (!nodes.empty()) {
    current = nodes.front();
    while (current == nullptr) {
      std::cout << std::setw(6) << "NI " << std::setw(6);
      nodes.pop();
      if (!nodes.empty()) {
        current = nodes.front();
      } else {
        return;
      }
    }

    nodes.pop();

    std::cout << std::setw(2) << current->key << std::setw(2);
    if (current->isRed) {
      std::cout << "(R)" << ' ';
    } else {
      std::cout << "(B)" << ' ';
    }
    if (current == root) {
      std::cout << "\n";
    }
    if (current == levelParent->rightChild) {
      std::cout << '\n';
      levelParent = current;
    }
    nodes.push(current->leftChild);
    nodes.push(current->rightChild);
  }
  std::cout << '\n';
}

template <typename T, typename U>
void Map<T,U>::printAsTree() {
  int o_size = m_size;
  std::queue<int> nils;
  bool hasNils = false;
  int powTwo = 0;
  int index = 1;
  int nilSum = 0;
  std::queue<MapNode<T,U>*> nodes;
  std::cout << std::setw((o_size - (index)) + ((o_size * 1.1 / pow(2, powTwo))));
  nodes.push(root);
  MapNode<T,U>* current = nullptr;
  MapNode<T,U>* levelParent = root;
  while (!nodes.empty()) {
    current = nodes.front();
    while (nodes.front() == nullptr) {
      hasNils = true;
      std::cout << "N" << std::setw(((o_size - (powTwo / 2)) / (pow(2, powTwo)))) << ' ';
      index++;
      nils.push(true);
      nodes.pop();
      if (!nodes.empty()) {
        current = nodes.front();
      } else {
        return;
      }
    }

    nodes.pop();
    std::cout << current->key << ((current->isRed) ? "R" : "B") << std::setw(((o_size - (powTwo / 2)) / (pow(2, powTwo)))) << ' ';
    if (hasNils && current->leftChild == nullptr && current->rightChild == nullptr) {
      nils.push(false);
    } else if ((hasNils && current->leftChild != nullptr) || (hasNils && current->rightChild != nullptr)) {
      nils.push(2);
    }
    index++;

    if (current == root) {
      std::cout << "\n";
      std::cout << std::setw((o_size - (index)) + ((o_size / pow(2, powTwo)) / 2 + index));
    }
    if (current == levelParent->rightChild) {
      std::cout << '\n';
      powTwo++;
      if (!hasNils) {
        std::cout << std::setw((o_size - (index)) + ((o_size / pow(2, powTwo)) / 2 + index));
      } else {
        std::cout << std::setw((o_size - (index)) + ((o_size / pow(2, powTwo)) / 2 + index));
      }

      if (hasNils) {
        while (!nils.empty()) {
          if (nils.front() == true) {
            if (nodes.empty()) {
              return;
            }
            std::cout << "" << std::setw(((o_size - (powTwo / 2)) / (pow(2, powTwo)))) << ' ';
            index++;
            std::cout << "" << std::setw(((o_size - (powTwo / 2)) / (pow(2, powTwo)))) << ' ';
            index++;
          } else if (nils.front() == 0) {
            if (nodes.empty()) {
              return;
            }
            // std::cout << "" << std::setw(((o_size - (powTwo / 2)) / (pow(2, powTwo)))) << ' ';
            // o_size++;
            // std::cout << "" << std::setw(((o_size - (powTwo / 2)) / (pow(2, powTwo)))) << ' ';
            // o_size++;
            if (nodes.front() == nullptr) {
              // nodes.pop();
              if (nodes.front() == nullptr) {
                // nodes.pop();
              }
              nils.pop();
              continue;
            } else {
              nils.pop();
              // std::cout << nodes.front()->key << std::setw(((m_size - (powTwo / 2)) / (pow(2, powTwo)))) << ' ';
              continue;
            }
          }
          nils.pop();
        }
      }
      levelParent = current;
    } else if (hasNils && current == levelParent->leftChild && levelParent->rightChild == nullptr) {
      std::cout << "N" << std::setw(((m_size - (powTwo / 2)) / (pow(2, powTwo)))) << ' ';
      nodes.pop();
      std::cout << '\n';
      std::cout << std::setw((m_size - (index)) + ((m_size / pow(2, powTwo)) / 2 + index));
      powTwo++;
    }

    nodes.push(current->leftChild);

    nodes.push(current->rightChild);
  }
  std::cout << '\n';
  std::cout << std::endl;
}

template <typename T, typename U>
void Map<T,U>::insert(T key) {
  if (root == nullptr) {
    root = new MapNode<T,U>(key);
    return;
  }

  bool isLeft = false;

  MapNode<T,U>* current = nullptr;
  MapNode<T,U>* parent = nullptr;
  if (key > root->key) {
    current = root->rightChild;
  } else if (key < root->key) {
    if (root->leftChild) {
      current = root->leftChild;
    } else {
      isLeft = true;
    }

  } else {
    return;
  }
  if (current) {
    while (current != nullptr) {
      if (key > current->key) {
        if (current->rightChild) {
          current = current->rightChild;
        } else {
          parent = current;
          current = current->rightChild;
          break;
        }
      } else if (key < current->key) {
        if (current->leftChild) {
          current = current->leftChild;
        } else {
          isLeft = true;
          parent = current;
          current = current->leftChild;
          break;
        }
      } else {
        return;
      }
    }
    current = new MapNode<T,U>(key, parent, true);
    m_size++;
    if (isLeft) {
      parent->leftChild = current;
    } else {
      parent->rightChild = current;
    }
  } else {
    parent = root;
    if (isLeft) {
      root->leftChild = new MapNode<T,U>(key, parent, true);
      current = root->leftChild;
    } else {
      root->rightChild = new MapNode<T,U>(key, parent, true);
      current = root->rightChild;
    }
    m_size++;
  }

  if (current->parent->parent == nullptr) {
    return;
  }

  fixInsert(current);
}

template <typename T, typename U>
void Map<T,U>::insert(std::initializer_list<T> keys) {
  for (auto i = keys.begin(); i != keys.end(); ++i) {
    insert(*i);
  }
}

template <typename T, typename U>
void Map<T, U>::insert(T key, U data) {
  if (root == nullptr) {
    root = new MapNode<T, U>(key);
    return;
  }

  bool isLeft = false;

  MapNode<T, U>* current = nullptr;
  MapNode<T, U>* parent = nullptr;
  if (key > root->key) {
    current = root->rightChild;
  } else if (key < root->key) {
    if (root->leftChild) {
      current = root->leftChild;
    } else {
      isLeft = true;
    }

  } else {
    return;
  }
  if (current) {
    while (current != nullptr) {
      if (key > current->key) {
        if (current->rightChild) {
          current = current->rightChild;
        } else {
          parent = current;
          current = current->rightChild;
          break;
        }
      } else if (key < current->key) {
        if (current->leftChild) {
          current = current->leftChild;
        } else {
          isLeft = true;
          parent = current;
          current = current->leftChild;
          break;
        }
      } else {
        return;
      }
    }
    current = new MapNode<T, U>(key, parent, true, data);
    m_size++;
    if (isLeft) {
      parent->leftChild = current;
    } else {
      parent->rightChild = current;
    }
  } else {
    parent = root;
    if (isLeft) {
      root->leftChild = new MapNode<T, U>(key, parent, true, data);
      current = root->leftChild;
    } else {
      root->rightChild = new MapNode<T, U>(key, parent, true, data);
      current = root->rightChild;
    }
    m_size++;
  }

  if (current->parent->parent == nullptr) {
    return;
  }

  fixInsert(current);
}


template <typename T, typename U>
void Map<T,U>::leftRotate(MapNode<T,U>* x) {
  MapNode<T,U>* y = x->rightChild;
  x->rightChild = y->leftChild;
  if (y->leftChild != nullptr) {
    y->leftChild->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == nullptr) {
    root = y;
  } else if (x == x->parent->rightChild) {
    x->parent->rightChild = y;
  } else if (x == x->parent->leftChild) {
    x->parent->leftChild = y;
  }
  x->parent = y;
  y->leftChild = x;
}

template <typename T, typename U>
void Map<T,U>::rightRotate(MapNode<T,U>* x) {
  MapNode<T,U>* y = x->leftChild;
  x->leftChild = y->rightChild;
  if (y->rightChild != nullptr) {
    y->rightChild->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == nullptr) {
    root = y;
  } else if (x == x->parent->rightChild) {
    x->parent->rightChild = y;
  } else if (x == x->parent->leftChild) {
    x->parent->leftChild = y;
  }
  x->parent = y;
  y->rightChild = x;
}

template <typename T, typename U>
void Map<T,U>::fixInsert(MapNode<T,U>* k) {
  while (k != nullptr && k != root && k->parent != nullptr && k->parent->isRed) {
    // If k's parent is the left subchild of its parent
    if (k->parent->parent->leftChild != nullptr && k->parent == k->parent->parent->leftChild) {
      // Create pointer to uncle (right subchild of k's grandparent)
      MapNode<T,U>* uncle = k->parent->parent->rightChild;
      // If uncle is RED
      if (uncle != nullptr && uncle->isRed) {
        // Set parent and uncle to black and grandparent to red
        k->parent->isRed = false;
        uncle->isRed = false;
        k->parent->parent->isRed = true;
        // Update k to it's grandparent
        k = k->parent->parent;
        // Else if uncle is BLACK
      } else {
        // If k is it's parent's right child
        if (k == k->parent->rightChild) {
          // Set k to its parent and left rotate
          k = k->parent;
          leftRotate(k);
        }
        // Set k's parent to BLACK and k's grandparent to RED, then right rotate k's grandparent
        k->parent->isRed = false;
        k->parent->parent->isRed = true;
        rightRotate(k->parent->parent);
      }
      // Else if k's parent is their grandparent's right child
    } else {
      MapNode<T,U>* uncle = k->parent->parent->leftChild;
      // If uncle is red
      if (uncle != nullptr && uncle->isRed) {
        // Set parent and uncle to black and grandparent to red
        k->parent->isRed = false;
        uncle->isRed = false;
        k->parent->parent->isRed = true;
        // Set k to k's grandparent
        k = k->parent->parent;
        // Else if uncle is black
      } else {
        // If k is k's parent's left child
        if (k == k->parent->leftChild) {
          // Set k to k's parent and right rotate
          k = k->parent;
          rightRotate(k);
        }
        // Set k's parent to BLACK and k's grandparent to RED then left rotate k's grandparent
        k->parent->isRed = false;
        k->parent->parent->isRed = true;
        leftRotate(k->parent->parent);
      }
    }
  }
  // Ensure that root is black
  root->isRed = false;
}

template <typename T, typename U>
MapNode<T,U>* Map<T,U>::search(T value) {
  MapNode<T,U>* current = root;

  while (current != nullptr) {
    if (value > current->key) {
      current = current->rightChild;
    } else if (value < current->key) {
      current = current->leftChild;
    } else {
      return current;
    }
  }

  return nullptr;
}

template <typename T, typename U>
void Map<T,U>::remove(T value) {
  MapNode<T,U>* z = search(value);
  MapNode<T,U>* y = nullptr;
  MapNode<T,U>* x = nullptr;
  MapNode<T,U>* parent = nullptr;

  if (z == nullptr) {
    return;
  }
  bool wasRed;
  y = z;
  if (y) {
    wasRed = y->isRed;
  } else {
    wasRed = false;
  }

  // delNode has no leftChild
  if (z->leftChild == nullptr) {
    x = z->rightChild;
    parent = z->parent;
    transplant(z, z->rightChild);

    // delNode has no rightChild
  } else if (z->rightChild == nullptr) {
    x = z->leftChild;
    parent = z->parent;
    transplant(z, z->leftChild);
    // delNode has both children
  } else {
    // Set y as smallest node in right subtree of delNode
    y = smallestChild(z->rightChild);
    wasRed = y->isRed;
    x = y->rightChild;
    parent = y->parent;
    // If y is a child of delNode
    if (y->parent == z) {
      if (x != nullptr) {
        x->parent = y;
      }
      // If y is not a child of delNode
    } else {
      transplant(y, y->rightChild);
      y->rightChild = z->rightChild;
      z->rightChild->parent = y;
    }
    transplant(z, y);
    y->leftChild = z->leftChild;
    z->leftChild->parent = y;
    y->isRed = z->isRed;
  }
  delete z;
  // If colour was black, call fixDelete
  if (wasRed == false) {
    fixDelete(x, parent);
  }
}



template <typename T, typename U>
void Map<T,U>::transplant(MapNode<T,U>* recipient, MapNode<T,U>* donor) {
  if (recipient->parent == nullptr) {
    root = donor;
  } else if (recipient == recipient->parent->leftChild) {
    recipient->parent->leftChild = donor;
  } else {
    recipient->parent->rightChild = donor;
  }
  if (donor) {
    donor->parent = recipient->parent;
  }
}

#endif

// 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16