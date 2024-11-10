#include "Heap.h"
using namespace std;
int main() {
  std::vector<int> list = {1,5,4,7,48,91,6,5,40,8,5,2,3,12,5,6,4,7,8,5,14,3,5};
  Heap<int> heap(list, list.size() + 1);
  heap.print();
  heap.insert(15);
  heap.print();
  heap.insert(2);
  heap.print();
  heap.insert(33);
  heap.print();
  heap.insert(200);
  heap.print();
  heap.remove(8);
  heap.print();
  heap.remove(8);
  heap.print();
  heap.remove({3, 12, 5, 6, 4, 7, 8, 5, 14, 3, 5});
  heap.print();
  heap.insert(201);
  heap.print();
  heap.remove({1,5,4,7,48,91,6,5,40,});
  heap.print();
  heap.insert(3);
  heap.print();
  std::vector<int> list2 = {4,8,7,9,6,5,2,1,5,7,9,6,5,2,1,5,6,5,2,1,5,7,9,4,7,9,4,4,5,7,9,3,6,6,5,2,1,5,7,9,4,5,44,2,1,5,4,9,8,7,6,5,4,8,4,6,5,7,9,8,5,4,8,4,5,7,77,66,4,8,7,9,6,5,2,1,5,7,9,6,5,2,1,5,6,5,2,1,5,7,9,4,7,9,4,4,5,7,9,3,6,6,5,2,1,5,7,9,4,5,44,2,1,5,4,9,8,7,6,5,4,8,4,6,5,7,9,8,5,4,8,4,5,7,77,66,4,8,7,9,6,5,2,1,5,7,9,6,5,2,1,5,6,5,2,1,5,7,9,4,7,9,4,4,5,7,9,3,6,6,5,2,1,5,7,9,4,5,44,2,1,5,4,9,8,7,6,5,4,8,4,6,5,7,9,8,5,4,8,4,5,7,77,66};
  heap.heapSort(list2);
  for (auto num: list2) {
    std::cout << num << ' ';
  }
  // heap.heapSort(list);
  // for (auto num: list) {
  //   std::cout << num << ' ';
  // }
  // std::cout << '\n';
}