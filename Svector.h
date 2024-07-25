#ifndef SVECTOR_H
#define SVECTOR_H

#include <cstddef>

template <class T, int cap>
class Svector {

  private:

  size_t capacity;
  size_t size;
  T data[cap];

  public:

  Svector();
  void push_back(T datum);
  void insert(T datum);
  void pop_back();
  void clear();
  T& operator[](int index);

};

#endif // SVECTOR_H