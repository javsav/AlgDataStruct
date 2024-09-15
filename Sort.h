#include <cstdlib>
#include <iostream>
#include <vector>

class Sort {
 private:
  void merge(std::vector<int>& list, int start, int end);
  void mergeStable(std::vector<std::pair<int, char>>& list, int start, int end);
  void quickSortHelper(std::vector<int>& list, int start, int end);

 public:
  void printList(std::vector<int>& list);
  std::vector<int>& selectionSort(std::vector<int>& list);
  std::vector<int>& insertionSortBasic(std::vector<int>& list);
  std::vector<int>& insertionSort(std::vector<int>& list);
  std::vector<int>& bubbleSort(std::vector<int>& list);
  std::vector<int>& quickSort(std::vector<int>& list);
  std::vector<int>& mergeSort(std::vector<int>& list);
  std::vector<std::pair<int, char>>& mergeSortStable(std::vector<std::pair<int, char>>& list);
  std::vector<int> countingSort(std::vector<int>& list);
};