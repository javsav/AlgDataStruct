// #include "QuickSort.h"
// #include "BubbleSort.h"
// #include <iostream>

// int main() {
//   BubbleSort sort;
//    std::vector<int> list;
//    std::vector<int> expected;
//   std::cout << (sort.sort(list) == expected) << "\n";
//    list = {5};
//    expected = {5};
//   std::cout << (sort.sort(list) == expected) << "\n";
//    list = {2, 1};
//    expected = {1, 2};
//   std::cout << (sort.sort(list) == expected) << "\n";
//    list = {1, 2};
//    expected = {1, 2};
//   std::cout << (sort.sort(list) == expected) << "\n";
//    list = {4, 2, 7, 1, 3};
//    expected = {1, 2, 3, 4, 7};
//   std::cout << (sort.sort(list) == expected) << "\n";
//    list = {1, 2, 3, 4, 7};
//    expected = {1, 2, 3, 4, 7};
//   std::cout << (sort.sort(list) == expected) << "\n";
//    list = {3, 1, 2, 3, 1};
//    expected = {1, 1, 2, 3, 3};
//   std::cout << (sort.sort(list) == expected) << "\n";
//    list = {-1, -3, 2, 0, -2};
//    expected = {-3, -2, -1, 0, 2};
//   std::cout << (sort.sort(list) == expected) << "\n";
//    list = {7, 7, 7, 7};
//    expected = {7, 7, 7, 7};
//   std::cout << (sort.sort(list) == expected) << "\n";
//    std::vector<int> list2(1000);
//   for (int i = 0; i < 1000; ++i) {
//     list2[i] = 1000 - i;
//   }
//    std::vector<int> expected2(1000);
//   for (int i = 0; i < 1000; ++i) {
//     expected2[i] = i + 1;
//   }
//   std::cout << (sort.sort(list) == expected) << "\n";
//    list = {10, 1, 8, 5, 3, 9, 4, 2, 7, 6};
//    expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   std::cout << (sort.sort(list) == expected) << "\n";
// }