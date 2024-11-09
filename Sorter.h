#include <vector>

class Sorter {
 public:
  std::vector<int>& insertionSort(std::vector<int>& list);
  std::vector<int>& selectionSort(std::vector<int>&);
  std::vector<int>& bubbleSort(std::vector<int>&);
  std::vector<int>& quickSort(std::vector<int>& list);
  std::vector<int>& mergeSort(std::vector<int>& list);
  private:
   void qSort(std::vector<int>& list, int start, int end);
   void mSort(std::vector<int>& list, int start, int end);
};