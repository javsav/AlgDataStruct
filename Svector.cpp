#include "Svector.h"
#include <iostream>

template <class T, int cap>
Svector<T, cap>::Svector() : capacity(cap), size(0) {}

template <class T, int cap>
void Svector<T, cap>::push_back(T datum) 
{
  if (size == capacity)
  {
    std::cout << "Svector full.\n";
    return;
  }

  data[size] = datum;
  size++;
}

template <class T, int cap>
void Svector<T, cap>::pop_back() 
{
  T clear;
  data[size] = clear;
  size--;
}

template <class T, int cap>
void Svector<T, cap>::insert(T datum) 
{
  if (size == capacity)
  {
    std::cout << "Svector full.\n";
    return;
  }

  for (int i = size; i >= 0; i--) {
    data[i+1] = data[i];
  }

  data[0] = datum;
  size++;
}

template <class T, int cap>
void Svector<T, cap>::clear() 
{
  T clear;
  for (int i = capacity - 1; i >= 0; i--) {
    data[i] = clear;
  }

  size = 0;
}

template <class T, int cap>
T& Svector<T, cap>::operator[](int index) {
  return data[index];
}



