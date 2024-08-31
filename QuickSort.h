#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "Sort.h"
#include <cstddef>
#include <stack>


class QuickSort: public Sort {
 
 private:
  void QuickSortHelper(std::vector<int>& list, int left, int right);

 public:
  std::vector<int>& sort(std::vector<int>& list);
  std::vector<int>& sortIterative(std::vector<int>& list);

};

#endif
