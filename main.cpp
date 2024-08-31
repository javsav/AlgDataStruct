#include "RecursiveBinarySearch.h"
#include "QuickSort.h"
#include <vector>
#include <iostream>
#include <vector>
#include <string>

int main(int argc, char *argv[]) {
  RecursiveBinarySearch search;
  QuickSort sort;
  // To store arguments for sorting and searching
  std::vector<int> list(argc - 1, 0);
  // For conversion of chars to int
 
  // Iterate through argument vector
  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      char* currentChar = argv[i];
      int currentArg = 0;
      // Iterate through current character array until null terminator
      while (*currentChar != '\0') {
        // Multiply by 10 for each digit after the first
        std::cout << *currentChar << "\n";
        currentArg *= 10;
        // Handle negative sign
        if (*currentChar == '-') {
          currentChar++;
          currentArg += (*currentChar - '0');
          currentArg *= -1;
          currentChar++;
          continue;       
        // Obtain the ASCII value by subtracting zero character and add to currentArg
        } else {
          currentArg += (*currentChar - '0');
          currentChar++;
          continue;
        }        
      }   
      // Add to list
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
    for (int number : list) {
      std::cout << number << " ";
    } std::cout << "\n";

  }
  return 0;  
}
