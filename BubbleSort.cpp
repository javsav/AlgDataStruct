#include "Sort.h"
#include "BubbleSort.h"
#include <cstddef>
#include <iostream>


std::vector<int>& BubbleSort::sort(std::vector<int>& list) {
  
  size_t n = list.size();
 
  // Pointer to index of final element in list continues to decrease iteration
  size_t right = n - 1;
  // Continue iterating through the array until the right pointer reaches the second item
  while (right >= 1) {
    // Iterate through the array and swap the positions of any items that are greater than those to their immediate right
    for (size_t left = 0; left < right; left++) {
      if (list[left] > list[left + 1]) {
        std::swap(list[left], list [left + 1]);
      }

      
    }
    // Decrement right pointer
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