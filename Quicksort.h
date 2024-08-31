#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "Sort.h"
#include <cstddef>


class Quicksort: public Sort {
 
 private:
  void quickSortHelper(std::vector<int>& list, int left, int right);

 public:
  std::vector<int>& sort(std::vector<int>& list);

};

#endif
