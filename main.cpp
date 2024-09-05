#include "Node.h"
#include "LinkedList.h"
#include <iostream>

int main() {

  int array[10] = {1,2,3,4,5,6,7,8,9,10};

  LinkedList newList(array, 10);
  //LinkedList newList;

  std::cout << newList.get(10) << "\n";
  newList.insertPosition(10, 2);
  std::cout << newList.get(10) << "\n";
  newList.printList();
  newList.deletePosition(3);
  newList.printList();
  newList.deletePosition(0);
  newList.printList();
  newList.deletePosition(10);
  newList.printList();
  newList.insertPosition(11, 100);
  newList.printList();





  
}