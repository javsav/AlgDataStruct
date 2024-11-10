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
  // heap.heapSort(list);
  // for (auto num: list) {
  //   std::cout << num << ' ';
  // }
  // std::cout << '\n';
}