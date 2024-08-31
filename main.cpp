#include "RecursiveBinarySearch.h"
#include "Quicksort.h"
#include <vector>
#include <iostream>

int main() {
  RecursiveBinarySearch search;
  Quicksort sort;

  std::vector<int> list =  {2,67,43,21,43,6,321,123,5,6,23,3,4,56,1,3,7,78};

  sort.sort(list);

  for (auto thing:list) {
    std::cout << thing << ", ";
  }


  std::cout << "\n" << search.search(list, 43) << "\n";


}