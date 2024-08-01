#include "Computer.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

Computer::Computer() : Player("Computer") {
  srand(time(NULL));
}

Move* Computer::makeMove() {
  int r = rand() % moves.size();
  auto it = moves.begin();
  std::advance(it, r);
  std::cout << "Computer plays " << it->second->getName() << ".\n";
  return it->second;
}