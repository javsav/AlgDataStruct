#include <vector>

class Sorter {
 public:
  std::vector<int>& insertionSort(std::vector<int>& list);
  std::vector<int>& selectionSort(std::vector<int>&);
  std::vector<int>& bubbleSort(std::vector<int>&);
  std::vector<int>& quickSort(std::vector<int>& list);
  std::vector<int>& mergeSort(std::vector<int>& list);
  std::vector<int>& heapSort(std::vector<int>& list);
  private:
   void heapifyDown(size_t i, std::vector<int>& list, size_t end);
   void qSort(std::vector<int>& list, int start, int end);
   void mSort(std::vector<int>& list, int start, int end);
   size_t left(size_t i);
   size_t right(size_t i);
};