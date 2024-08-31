#include "Quicksort.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

Quicksort::Quicksort() {
  std::srand(std::time(nullptr));

}

std::vector<int> Quicksort::sort(std::vector<int>& list) {

  
  int end = list.size() - 1;
  int start = 0;

  quickSortHelper(list, start, end);
  
  return list;
   
}

void Quicksort::quickSortHelper(std::vector<int>& list, size_t start, size_t end) {


  if (start >= end) {
    return;
  }
  
  int size = end - start + 1; 
  
  
  // size_t pivotValueIndex;
  size_t pivotIndex = start;
  
  if (size >= 3) {
    std::swap(list[2], list[end]);       
  } else {
    int rand = std::rand() % size;
    std::swap(list[rand - 1], list[end]);
  }

  int pivotValue = list[end];


  for (size_t i = start; i <= end; i++) {
    if (list[i] < pivotValue) {
      std::swap(list[i], list[pivotIndex++]);    
    }
  }

  std::swap(list[end], list[pivotIndex++]);

  return quickSortHelper(list, start, pivotIndex - 1);
  return quickSortHelper(list, pivotIndex + 1, end); 

  
}

int main() {
  Quicksort sorter;

   std::vector<int> list = {2,7,4,1,3,2,6,7,99,5,4,234,3};

    sorter.sort(list);

  for (auto i = list.begin(); i != list.end(); ++i) {
    std::cout << *i << "\n";
  }
}