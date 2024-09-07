#include "RecursiveBinarySearch.h"
#include "Sort.h"
#include "QuickSort.h"
#include "BubbleSort.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main(int argc, char *argv[]) {
 
  RecursiveBinarySearch search;
  QuickSort sort;
  // To store arguments for sorting and searching
  std::vector<int> list;
  std::string input;

  std::string currentLine;
     
  std::getline(std::cin, currentLine, '\n');
  // Convert input to stream
  std::stringstream ss(currentLine);
  std::string chunk;          
  // Iterate through currentLine with space as delimiter and place section in chunk string
  while (std::getline(ss, chunk, ' ')) {
    // Try in case integer out of range
    try {
      stoi(chunk);
    // If out of range, continue to next argument
    } catch (...) {
      continue;
    }
    // Append string to integer to array
    list.push_back(stoi(chunk));
  }
  

  // Mathematical method
  // Iterate through argument vector if arguments passed to main

  // for (int i = 1; argv[i] != nullptr; i++) {
  //   char* currentChar = argv[i];
  //   int currentArg = 0;
  //   // Iterate through current character array until null terminator
  //   while (*currentChar != '\0') {
  //     // Set values outside range of int to 0
  //     if (abs(currentArg) > INT32_MAX / 10) {
  //       currentArg = 0;
  //       currentChar++;
  //       continue;
  //     }
  //     // Multiply by 10 for each digit after the first
  //     currentArg *= 10;
  //     // Handle negative sign
  //     if (*currentChar == '-') {
  //       currentChar++;
  //       currentArg += (*currentChar - '0');
  //       currentArg *= -1;
  //       currentChar++;
  //       continue;          
  //     } else if (currentArg >= 0) {
  //       // Obtain the ASCII value by subtracting zero character and add to currentArg
  //       currentArg += (*currentChar - '0');
  //       currentChar++;
  //       continue;
  //     } else {
  //       currentArg += ((*currentChar - '0') * -1);
  //       currentChar++;
  //     }
  //   }
  //     // Add to list
  //     list.push_back(currentArg);
  //     // Discard value outside of int range
      
  // }
  
  // Sort list
  sort.sort(list);

  // Search for the number 1 in the list
  if (search.search(list, 1)) {
    std::cout << "true ";
    
  } else {
    std::cout << "false ";
  }

  // Print the sorted list
  for (auto i = list.begin(); i != list.end(); ++i) {
    std::cout << *i << " ";
  } 
  std::cout << std::endl;

  return 0;
}
