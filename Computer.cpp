#include "Computer.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

Computer::Computer() : Player("Computer") {
  // Set random seed to system time //
  srand(time(NULL)); 
}

Move* Computer::makeMove() {
  
  // Random move selection //

  /*int r = rand() % moves.size();
  auto it = moves.begin();
  std::advance(it, r);
  std::cout << "Computer plays " << it->second->getName() << ".\n";
  return it->second;*/

  // Computer only plays rock //
  return moves["Rock"];
}