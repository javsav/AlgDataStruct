#include "Node.h"
#include "LinkedList.h"
#include <iostream>

int main() {

  int array[10] = {0,1,2,3,4,5,6,7,8,9};

  LinkedList newList(array, 10);
  //LinkedList newList;

  std::cout << newList.get(10) << "\n";
  
}