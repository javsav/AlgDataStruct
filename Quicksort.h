#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "Sort.h"
#include <cstddef>


class Quicksort {

 public:
 Quicksort();
 std::vector<int> sort(std::vector<int>& list);
 void quickSortHelper(std::vector<int>& list, size_t left, size_t right);
};

#endif
