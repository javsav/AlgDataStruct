#include "Sort.h"
#include "BubbleSort.h"
#include <cstddef>
#include <iostream>


std::vector<int>& BubbleSort::sort(std::vector<int>& list) {
  
  size_t n = list.size();
  
  size_t right = n - 1;

  while (right >= 1) {

    for (size_t left = 0; left < right; left++) {
      if (list[left] > list[left + 1]) {
        std::swap(list[left], list [left + 1]);
      }

      
    }
    right--;
  }

  return list;

  
  
}

// int main() {
//   BubbleSort sorter;

//   std::vector<int> list = {2,7,4,1,3,2,6,7,99,5,4,234,3};

//   sorter.sort(list);

//   for (auto i = list.begin(); i != list.end(); ++i) {
//     std::cout << *i << "\n";
//   }

// }