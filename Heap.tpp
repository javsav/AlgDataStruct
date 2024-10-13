//
//  Heap.cpp
//  Heap - Implementation of a Min-Heap data structure
//

#ifndef Tree_hpp
#define Tree_hpp

#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>
#include <cmath>
#include <iomanip>

template <typename T>
class Heap {
 private:
  // Define an alias for the underlying data structure (vector) and its size type
  typedef std::vector<T> heap;
  typedef typename heap::size_type heapIndex;

  // Internal storage for the heap elements
  heap tree;

  // Helper functions to calculate child and parent node positions based on index
  heapIndex getLeftChildPosition(heapIndex i) {
    // Left child is at index 2 * i
    return (2 * i);
  }

  heapIndex getRightChildPosition(heapIndex i) {
    // Right child is at index (2 * i) + 1
    return (2 * i) + 1;
  }

  heapIndex getParentPosition(heapIndex i) {
    // Parent is at floor((i - 1) / 2) using integer division
    return (heapIndex)std::floor(i / 2);
  }

  // Function to balance new heap
  void heapifie(heapIndex index) {    
    if (index >= tree.size() - 1) {
      return;
    }
    int leftIndex = getLeftChildPosition(index);
    int rightIndex = getRightChildPosition(index);

    if (leftIndex < tree.size() && tree[leftIndex] < tree[index]) {
      std::swap(tree[index], tree[leftIndex]);
      heapifie(leftIndex);
      heapifie(index);
    } else {
      heapifie(leftIndex);
    }
    if (rightIndex < tree.size() && tree[rightIndex] < tree[index]) {
      std::swap(tree[index], tree[rightIndex]);
      heapifie(rightIndex);
      heapifie(index);
    } else {
      heapifie(rightIndex);
    }    

  }

  // Function to assist with heapSort
  void heapifieSubarray(heapIndex index, heapIndex end) {
    if (index >= end) {
      return;
    }
    int leftIndex = getLeftChildPosition(index);
    int rightIndex = getRightChildPosition(index);
    int min = index;

    if (leftIndex < end && tree[leftIndex] < tree[min]) {
      min = leftIndex;      
    }
    if (rightIndex < end && tree[rightIndex] < tree[min]) {
      min = rightIndex;
    }

    if (min != index) {
      std::swap(tree[min], tree[index]);
      heapifieSubarray(min, end);
    } 
  }


  // Function to maintain the min-heap property by swapping elements down the tree
  heapIndex heapifyDown(heapIndex index) {    
    if (index >= tree.size() - 1) {
      return this->tree.size();
    }    

    heapIndex leftIndex = getLeftChildPosition(index);
    heapIndex rightIndex = getRightChildPosition(index);
    heapIndex min = index;

    if (leftIndex < tree.size() && tree[leftIndex] < tree[min]) {
      min = leftIndex;
    }
    if (rightIndex < tree.size() && tree[rightIndex] < tree[min]) {
      min = rightIndex;
    }

    if (min != index) {
      std::swap(tree[min], tree[index]);
      return heapifyDown(min);
    }

    return this->tree.size();
  }

 public:
  // Default constructor - creates an empty heap with a dummy element at index 0
  Heap() {
    this->tree.push_back((T)NULL);
  }

  operator heap() {
    return tree;
  }

  // Constructor that builds a min-heap from an existing vector
  Heap(std::vector<T>& tree) {
    this->heapify(tree);
  }

  // Check if the heap is empty
  bool isHeapEmpty() {
    return this->tree.size() <= 1;
  }

  // Print the contents of the heap in tree-like structure
  void printHeap() {
    int powTwo = 0;
    heapIndex index = 1;
    int cumSum = 0;
    while (index < tree.size()) {
      std::cout << std::setw((tree.size() - (index) ) + ((tree.size() / pow(2, powTwo))/2+index));
      while (cumSum < pow(2, powTwo) && index < tree.size()) {
        std::cout << tree[index] << std::setw(((tree.size() - (powTwo / 2)) / (pow(2, powTwo)))) << ' ';
        index++;
        cumSum++;
      }
      std::cout << '\n';
      cumSum = 0;
      powTwo++;
    }
  std::cout << '\n';
  }

  // Build a min-heap from an existing vector
  void heapify(std::vector<T>& tree) {
    // Insert a dummy element at the beginning to simplify calculations
    tree.insert(tree.begin(), (T)NULL);

    this->tree = tree;    
    
    //heapIndex root = 1;
    
    for (int i = (tree.size() / 2) - 1; i >= 1; i--) {
      heapifyDown(i);
    }
  }

  // Helper function to print the contents of a vector
  void printVector(std::vector<T> numVector) {
    std::cout << "[ ";
    for (heapIndex index = 0; index < numVector.size(); index++) {
      // Print only non-dummy elements
      if (numVector.at(index) != (T)NULL) {
        std::cout << numVector.at(index);
        if (index != (numVector.size() - 1)) {
          std::cout << ", ";
        }
      }
    }
    std::cout << " ]" << std::endl;
  }

  // Remove the minimum element from the heap
  T popTop() {
    if (this->isHeapEmpty()) {
      // Return a minimum value if the heap is empty
      return std::numeric_limits<T>::min();
    }
    const heapIndex ROOT_INDEX = 1;

    // Replace the root with the last element
    T topElement = this->tree.at(ROOT_INDEX);
    std::cout << "Removed top element: " << topElement << std::endl;
    std::cout << "Placing index: " << (this->tree.size() - 1) << "(" << this->tree.at(this->tree.size() - 1) << ") to the top" << std::endl;
    this->tree.at(ROOT_INDEX) = this->tree.at(this->tree.size() - 1);
    this->tree.pop_back();

    std::cout << "Checking the if the heap condition is valid after popping out top of heap: " << topElement << std::endl;
    // Restore the heap property by heapifying down from the root
    heapIndex parent = ROOT_INDEX;
    this->heapifyDown(parent);
    return topElement;
  }

  // Sort a vector using the heap sort algorithm
  std::vector<T> heapSort(std::vector<T>& numList) {
    Heap<T> sorter(numList);
    
    heapIndex end = sorter.tree.size() - 1;
    heapIndex i = 1;
    while (end >= 2) {
      std::swap(sorter.tree[i], sorter.tree[end]);
      sorter.heapifieSubarray(i, end);      
      end--;
    }
    std::reverse(sorter.tree.begin(), sorter.tree.end());
    sorter.tree.pop_back();
    return sorter;
  }

  
  // Insert an element into the heap
  void insert(T element) {
    this->tree.push_back(element);

    heapIndex i = this->tree.size() - 1;

    while (i != 0 && this->tree[getParentPosition(i)] > this->tree[i]) {
      std::swap(this->tree[getParentPosition(i)], this->tree[i]);
      i = getParentPosition(i);
    }
  }

  // Remove an element from the heap
  void remove(T value) {
    heapIndex i = 1;

    while (i < tree.size()) {
      if (tree[i] == value) {
        break;
      }
      i++;
    }
  
    std::swap(tree[i], tree[tree.size() - 1]);
    auto it = tree.begin();
    std::advance(it, tree.size()-1);
    tree.erase(it);
    heapIndex leftChild = getLeftChildPosition(i);
    heapIndex rightChild = getRightChildPosition(i);

    if (tree[leftChild] < tree[rightChild]) {
      while (leftChild < tree.size() && tree[i] > tree[leftChild]) {
        std::swap(tree[i], tree[leftChild]);
        i = leftChild;
        leftChild = getLeftChildPosition(i);
      }
    } else {
      while (rightChild < tree.size() && tree[i] > tree[rightChild]) {
        std::swap(tree[i], tree[rightChild]);
        i = rightChild;
        rightChild = getRightChildPosition(i);
      }
    }
  }

  // TO BE IMPLEMENTED
  // Get the minimum element (in this case, the minimum element of the min-heap)
  T getMin() {
    return tree[1];
  }
};

#endif /* Tree_hpp */
