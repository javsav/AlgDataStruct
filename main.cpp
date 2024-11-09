#include "LinkedList.h"

int main() {
  

  std::vector<int> list = {2,6,3,4,6,8,7,2,1,3,9};

  LinkedList<int> llist(list);

  

  llist.print();

  llist.push_front(3);

  llist.print();

  llist.deleteValue(4);

  llist.print();

  llist.deleteValue(3);

  llist.print();

  llist.deleteValue(9);

  llist.print();

  llist.printTail();

  llist.printHead();

  llist.insert(3, 12);

  llist.print();

  llist.push_back(69);

  llist.print();

  llist.printTail();
}