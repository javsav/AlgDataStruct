#include "QuickSort.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

std::vector<int>& QuickSort::sortIterative(std::vector<int>& list) {
  // Struct to be stored within the virtual stack calls
  struct QuickSortCall {
    // List is not required as we have a pointer to it already and each call
    // works on the same list
    int left;
    int right;
  };

  // Use std::stack to emulate the call stack
  std::stack<QuickSortCall> callStack;

  // Push the first 'call' to the virtual stack so that the loop has something to process
  callStack.push(QuickSortCall{0, (int)list.size() - 1});

  // Continue processing stack 'frames' until the virtual stack is empty
  while (!callStack.empty()) {
    // Copy the current virtual stack call left and right pointers
    int left = callStack.top().left;
    int right = callStack.top().right;

    // Define current list size and pivotIndex
    size_t size = left - right + 1;
    int pivotIndex = left;

    // If 'base case' is reached, pop the current stack 'frame' and continue to
    // next iteration
    if (left >= right) {
      callStack.pop();
      continue;
    }

    // Choose third item as pivot if size > 3 and swap with end of list section
    // (assignment requirement)
    if (size > 3) {
      std::swap(list[left + 2], list[right]);
    }  // Otherwise use the final element

    // Pivot value is at the final index of the current list
    int pivotValue = list[right];

    for (size_t i = left; i < right; i++) {
      // Swap smaller/equal items with the pivot index and increment the index
      if (list[i] <= pivotValue) {
        std::swap(list[i], list[pivotIndex++]);
      }
    }

    // Place the pivot in its appropriate index
    std::swap(list[pivotIndex], list[right]);

    // Remove the current "recursive call" from the stack
    callStack.pop();

    // Push the next "recursive call structs" to the stack
    callStack.push(QuickSortCall{left, pivotIndex - 1});
    callStack.push(QuickSortCall{pivotIndex + 1, right});
  }

  return list;
}

std::vector<int>& QuickSort::sort(std::vector<int>& list) {
  // Left pointer
  int left = 0;
  // Right pointer (final index)
  int right = list.size() - 1;

  QuickSortHelper(list, left, right);
  
  return list;
   
}

void QuickSort::QuickSortHelper(std::vector<int>& list, int left, int right) {

  // Base Case: return if the list has 1 or less items
  if (left >= right) {
    return;
  }
  
  // Obtain current size
  size_t size = right - left + 1;

  
  // Set pivotIndex to start of current list section  
  size_t pivotIndex = left;
  
  // Choose third item as pivot if size > 3 and swap with end of list section (assignment requirement
  if (size > 3) {
    std::swap(list[left + 2], list[right]);       
  } // Otherwise use the final element


  // Pivot value is at the final index of current list
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
  QuickSortHelper(list, left, pivotIndex - 1);
  QuickSortHelper(list, pivotIndex + 1, right); 
  
  
}