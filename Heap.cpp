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

template <typename T>
class Heap {
 private:
  // Define an alias for the underlying data structure (vector) and its size type
  typedef std::vector<T> heap;
  typedef heap::size_type heapIndex;

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

  // Function to maintain the min-heap property by swapping elements down the tree
  heapIndex heapifyDown(heapIndex index) {
    heapIndex leftChildIndex = this->getLeftChildPosition(index);
    T leftChild = (leftChildIndex < this->tree.size()) ? this->tree.at(leftChildIndex) : std::numeric_limits<T>::min();

    heapIndex rightChildIndex = this->getRightChildPosition(index);
    T rightChild = (rightChildIndex < this->tree.size()) ? this->tree.at(rightChildIndex) : std::numeric_limits<T>::min();

    // Find the child with the larger value
    heapIndex minValueChildIndex = (leftChild < rightChild) ? leftChildIndex : rightChildIndex;

    // If a child has a larger value, swap it with the parent and recursively heapify down
    if (minValueChildIndex < this->tree.size()) {
      if (this->tree.at(minValueChildIndex) < this->tree.at(index)) {
        std::cout << "Swap positions " << minValueChildIndex << "(" << this->tree.at(minValueChildIndex) << ") and" << index << "(" << this->tree.at(index) << ")." << std::endl;
        std::swap(this->tree.at(minValueChildIndex), this->tree.at(index));
        // Recursively fix the heap property
        this->heapifyDown(minValueChildIndex);
        return minValueChildIndex;
      }
    }
    // Reached a leaf node or no child has a larger value, return the current index
    return this->tree.size();
  }

 public:
  // Default constructor - creates an empty heap with a dummy element at index 0
  Heap() {
    this->tree.push_back((T)NULL);
  }

  // Constructor that builds a min-heap from an existing vector
  Heap(std::vector<T> tree) {
    this->heapify(tree);
  }

  // Check if the heap is empty
  bool isHeapEmpty() {
    return this->tree.size() <= 1;
  }

  // Print the contents of the heap
  void printHeap() {
    this->printVector(this->tree);
  }

  // Build a min-heap from an existing vector
  void heapify(std::vector<T> tree) {
    // Insert a dummy element at the beginning to simplify calculations
    tree.insert(tree.begin(), (T)NULL);

    this->tree = tree;

    // Start from the last non-dummy element and work backwards to maintain the heap property
    for (heapIndex index = this->tree.size() - 1; index >= 1; index--) {
      this->heapifyDown(index);
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
  std::vector<T> heapSort(std::vector<T> numList) {
    Heap<T> tree1;
    // Build a min-heap from the input vector
    for (typename std::vector<T>::size_type index = 0; index < numList.size(); index++) {
      tree1.insert(numList[index]);
    }

    std::vector<T> sortedNumList;
    // Extract the minimum elements one by one and add them to the sorted list
    while (!tree1.isHeapEmpty()) {
      sortedNumList.push_back(tree1.popTop());
      this->printVector(sortedNumList);
    }
    return sortedNumList;
  }

  // TO BE IMPLEMENTED
  // Insert an element into the heap
  void insert(T element) {
  }

  // TO BE IMPLEMENTED
  // Remove an element from the heap
  void remove(T value) {
  }

  // TO BE IMPLEMENTED
  // Get the minimum element (in this case, the minimum element of the min-heap)
  T getMin() {
  }
};

#endif /* Tree_hpp */
