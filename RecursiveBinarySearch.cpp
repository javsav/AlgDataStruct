#include "RecursiveBinarySearch.h"



bool RecursiveBinarySearch::search(std::vector<int>& list, int target) {
  
  // Declare left and right pointers
  int left = 0;
  int right = list.size() - 1;
  
  // Call recursive function
  if (binarySearchHelper(list, target, left, right) == - 1) {
    return false;
  // Return true if index of target is found
  } else {
    return true;
  }

}

int RecursiveBinarySearch::binarySearchHelper(std::vector<int>& list, int target, int left, int right){
  
  // Base case
  if (right - left < 0) {
    return -1;
  }
  
  // Divide current section of list in half
  int mid = (left + right) / 2;
  // If target is found, return index
  if (list[mid] == target) {    
    return mid;
  // Else, continue recursively dividing and searching based on value of middle element
  } else if (list[mid] < target) {
    return binarySearchHelper(list, target, mid + 1, right);  
  } else {
    return binarySearchHelper(list, target, left, mid - 1);
  }

  // If no target is found after search, return -1
  return -1;

}

// int main() {
//   RecursiveBinarySearch searcher;

//   std::vector<int> list = { 1, 3, 5, 4, -5, 100, 7777, 2014 };

//   searcher.search(list, 1);
// }