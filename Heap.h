#ifndef HEAP_H
#define HEAP_H
#include <cstddef>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <initializer_list>
template <typename T>
class Heap {

 private:
  T* m_heap;
  size_t m_size = 0;
  size_t capacity;
  void resize();
  void expand();

 public:
  Heap(size_t capacity);
  Heap(std::vector<T> list, size_t capacity);
  size_t left(size_t i);
  size_t right(size_t i);
  size_t parent(size_t i);
  void heapifyDown(size_t i);
  void print();
  void display();
  size_t size();
  void siftUp(size_t i);
  void insert(T key);
  void heapSort(std::vector<T>& list);
  void heapifyDown(size_t i, std::vector<T>& list, size_t end);
  void siftUp(size_t i, std::vector<T>& list);
  void remove(T value);
  void remove(std::initializer_list<T> values);
  size_t search(T value);




};

template <typename T>
void Heap<T>::resize() {
  T* newHeap = new T[capacity * 2] {{}};

  memcpy(newHeap, m_heap, capacity * sizeof(int));

  delete m_heap;

  m_heap = newHeap;

  capacity = capacity * 2;
}

template <typename T>
void Heap<T>::expand() {
  T* newHeap = new T[capacity * 2]{{}};

  delete m_heap;

  m_heap = newHeap;

  capacity = capacity * 2;
}

template <typename T>
Heap<T>::Heap(size_t capacity) {
  m_heap = new T[capacity + 1] {{}};
  capacity = capacity + 1;
}

template <typename T>
Heap<T>::Heap(std::vector<T> list, size_t capacity) {
  m_heap = new T[capacity + 1] {{}};
  capacity = capacity + 1;

  while (list.size() > capacity) {
    expand();
  }

  for (int i = 0; i < list.size(); i++) {    
    m_heap[i] = list[i];
    m_size++;
  }

  int i = m_size/2;

  while (i >= 0) {
    heapifyDown(i);
    i--;
  }
}

  template <typename T>
  size_t Heap<T>::left(size_t i) {
    return (i * 2) + 1;
  }
  template <typename T>
  size_t Heap<T>::right(size_t i) {
    return (i * 2) + 2;
  }
  template <typename T>
  size_t Heap<T>::parent(size_t i) {
    return (i - 1) / 2;
  }

  template <typename T>
  void Heap<T>::heapifyDown(size_t i) {

    if (i >= m_size) {
      return;
    }

    int max = i;

    int l = left(i);
    int r = right(i);

    if (l < m_size && m_heap[l] > m_heap[max]) {
      max = l;
    }
    if (r < m_size && m_heap[r] > m_heap[max]) {
      max = r;
    }
    if (max != i) {
      std::swap(m_heap[i], m_heap[max]);
      heapifyDown(max);
    }
  }

  template <typename T>
  void Heap<T>::print() {
    int powTwo = 0;
    int index = 0;
    int cumSum = 0;
    while (index < m_size) {
      std::cout << std::setw((m_size - (index) ) + ((m_size / pow(2, powTwo))/2+index));
      while (cumSum < pow(2, powTwo) && index < m_size) {
        std::cout << m_heap[index] << std::setw(((m_size - (powTwo / 2)) / (pow(2, powTwo)))) << ' ';
        index++;
        cumSum++;
      }
      std::cout << '\n';
      cumSum = 0;
      powTwo++;
    }
  std::cout << '\n';
  }

  template <typename T>
  void Heap<T>::display() {
    for (int i = 0; i < m_size; i++) {
      std::cout << m_heap[i] << " ";
    }
    std::cout << '\n';
  }

  template <typename T>
  size_t Heap<T>::size() {
    return m_size;
  }

  template <typename T>
  void Heap<T>::siftUp(size_t i) {
    int parent = this->parent(i);
    while (parent >=0 && m_heap[parent] < m_heap[i]) {
      std::swap(m_heap[parent], m_heap[i]);
      i = parent;
      parent = this->parent(i);
    }
  }

  template <typename T>
  void Heap<T>::insert(T key) {
    m_size++;
    if (m_size == capacity) {
      resize();
    }
    m_heap[m_size - 1] = key;
    siftUp(m_size - 1);
  }

  template <typename T>
  void Heap<T>::heapSort(std::vector<T>& list) {
    int i = list.size() / 2;
    int end = list.size();
    while (i >= 0) {
      heapifyDown(i, list, end);
      i--;
    }

    
    int start = 0;
    while (end > 1) {
      std::swap(list[start], list[end - 1]);
      end--;
      heapifyDown(start, list, end);
    }
  } 

  template <typename T>
  void Heap<T>::heapifyDown(size_t i, std::vector<T>& list, size_t end) {
    if (i >= end) {
      return;
    }

    int max = i;

    int l = left(i);
    int r = right(i);

    if (l < end && list[l] > list[max]) {
      max = l;
    }
    if (r < end && list[r] > list[max]) {
      max = r;
    }
    if (max != i) {
      std::swap(list[i], list[max]);
      heapifyDown(max, list, end);
    }
  }

  template <typename T>
  void Heap<T>::siftUp(size_t i, std::vector<T>& list) {
    int parent = this->parent(i);
    while (parent >= 0 && list[parent] < list[i]) {
      std::swap(list[parent], list[i]);
      i = parent;
      parent = this->parent(i);
    }
  }

  template <typename T>
  void Heap<T>::remove(T value) {
    size_t i = search(value);
    if (i == -1) {
      return;
    }
    std::swap(m_heap[i], m_heap[m_size - 1]);
    m_heap[m_size - 1] = T();
    m_size--;
    heapifyDown(i);    
  }

  template <typename T>
  void Heap<T>::remove(std::initializer_list<T> values) {
    for (auto i = values.begin(); i != values.end(); i++) {
      remove(*i);
    }
  }

  template <typename T>
  size_t Heap<T>::search(T value) {
    size_t i = 0;

    while (i < m_size) {
      if (m_heap[i] == value) {
        return i;
      }
      i++;
    }
    return -1;
  }

#endif
