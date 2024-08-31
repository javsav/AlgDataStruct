#include "Quicksort.h"
#include <ctime>
#include <cstdlib>
#include <iostream>


std::vector<int>& Quicksort::sort(std::vector<int>& list) {
  // Left pointer
  int left = 0;
  // Right pointer (final index)
  int right = list.size() - 1;

  quickSortHelper(list, left, right);
  
  return list;
   
}

void Quicksort::quickSortHelper(std::vector<int>& list, int left, int right) {

  // Base Case: return if the list has 1 or less items
  if (left >= right) {
    return;
  }
  
  // Obtain current size
  size_t size = right - left + 1;

  
  // Set pivotIndex to start of current list section  
  size_t pivotIndex = left;
  

  // Choose third item as pivot if size > 3 and swap with end of list section
  if (size > 3) {
    std::swap(list[left + 2], list[right]);       
  }

  // Pivot value is at the end of the section
  int pivotValue = list[right];


  for (size_t i = left; i < right; i++) {
    // Swap smaller/equal items with the pivot index and increment the index
    if (list[i] <= pivotValue) {
      std::swap(list[i], list[pivotIndex++]);    
    }
  }

  // Place the pivot in its appropriate index
  std::swap(list[pivotIndex], list[right]);

  // Recursively call the algorithm on the sections below and above the pivot
  quickSortHelper(list, left, pivotIndex - 1);
  quickSortHelper(list, pivotIndex + 1, right); 

  
}

// int main() {
//   Quicksort sorter;

//    std::vector<int> list = {2,7,4,1,3,2,6,7,99,5,4,234,3};

//     std::vector<int> newlist = sorter.sort(list);

//   for (auto i = newlist.begin(); i != newlist.end(); ++i) {
//     std::cout << *i << ", ";
//   }
// }