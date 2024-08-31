#ifndef RECURSIVEBINARYSEARCH_H
#define RECURSIVEBINARYSEARCH_H
#include <vector>

class RecursiveBinarySearch {
 
 private:
  int binarySearchHelper(std::vector<int>& list, int target, int left, int right);

 public:
  bool search(std::vector<int>& list, int target);
};

#endif