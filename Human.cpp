#include "Human.h"

char Human::makeMove() {
  std::cout << "\nEnter move:";
  std::cin >> currentMove;
  std::cout << "\n";
  if (currentMove != 'R' && currentMove != 'P' && currentMove != 'S') {
    std::cout << "Invalid move. Setting move to rock.\n";
    currentMove = 'R';
  }
  
  return currentMove;
}
