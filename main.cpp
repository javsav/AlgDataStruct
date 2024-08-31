#include "RecursiveBinarySearch.h"
#include "Sort.h"
#include "QuickSort.h"
#include "BubbleSort.h"
#include <vector>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::cout << "TEST:" << argv[0] << argv[1] << argv[2] << "\n";
  //std::cout << argv[0] << "\n";
  //std::cout << argv[1] << "\n";
  RecursiveBinarySearch search;
  BubbleSort sort;
  // To store arguments for sorting and searching
  std::vector<int> list(argc - 1, 0);

    // For conversion of chars to int
    // UNIVERSITY SYSTEM SUCKS DOESN'T LET YOU WRITE YOUR OWN FUCKING CODE EVEN
    // THOUGH YOU PUT HEAPS OF EFFORT INTO IT
    // // Iterate through argument vector
    // if (argc > 1) {
    //   for (int i = 1; i < argc; i++) {
    //     char* currentChar = argv[i];
    //     int currentArg = 0;
    //     // Iterate through current character array until null terminator
    //     while (*currentChar != '\0') {
    //       // Multiply by 10 for each digit after the first
    //       currentArg *= 10;
    //       // Handle negative sign
    //       if (*currentChar == '-') {
    //         currentChar++;
    //         currentArg += (*currentChar - '0');
    //         currentArg *= -1;
    //         currentChar++;
    //         continue;
    //       // Obtain the ASCII value by subtracting zero character and add to
    //       currentArg } else {
    //         currentArg += (*currentChar - '0');
    //         currentChar++;
    //         continue;
    //       }
    //     }
    //     // Add to list
    //     list[i - 1] = currentArg;
    //   }

   if (argc > 1) {
      for (int i = 1; i < argc; i++) {
        std::string currentCharArray = argv[i];
        int currentArg = stoi(currentCharArray);
        list[i - 1] = currentArg;
      }   

      // Sort list
      sort.sort(list);

      // Search for the number 1 in the list
      if (search.search(list, 1)) {
        std::cout << "true ";
      } else {
        std::cout << "false ";
      }

      // Print the sorted list
      for (auto i = 0; i < list.size(); i++) {
        std::cout << list[i] << " ";
      } std::cout << "\n";
    }
  return 0;
}
