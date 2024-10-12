#include "Heap.tpp"

int main() {
  
  std::vector<int> list = {9,8,7,6,5,4,3,2,1};

  Heap<int> heap(list);

  heap.printHeap();

  heap.remove(2);

  heap.printHeap();

  std::vector<int> unsorted = {9, 8, 7, 6, 2, 4, 5, 3, 2, 3, 11, 1, 1, 9, 9, 5, 4, 3, 2, 1};

  std::vector<int> sortedVec = heap.heapSort(unsorted);

  for (auto i = sortedVec.begin(); i != sortedVec.end(); ++i) {
    std::cout << *i << ' ';
  }
  std::cout << '\n';



  // heap.insert(1);

  // heap.printHeap();

  // heap.insert(3);

  // heap.printHeap();

  // heap.insert(8);

  // heap.printHeap();

  // heap.printVector(heap);

  // heap.insert(12);

  // heap.printHeap();



  // heap.insert(7);

  // heap.insert(3);

  // heap.insert(9);

  // heap.insert(5);

  // heap.printHeap();

  // heap.insert(2);

  // heap.printHeap();

  // heap.insert(2);

  // heap.printHeap();

  // heap.insert(7);

  // heap.printHeap();

  // heap.insert(9);

  // heap.printHeap();

  // heap.insert(4);

  // heap.printHeap();

  // heap.insert(1);

  // heap.printHeap();

  // heap.remove(1);

  // heap.printHeap();
}
