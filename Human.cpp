#include "Human.h"
#include "Rock.h"

Move* Human::makeMove() {
  std::cout << "\nEnter move: ";
  std::cin >> currentMove;
  std::cout << "\n";
  if (moves.count(currentMove)) {
    return moves[currentMove];
  } else {
    std::cout << "Invalid move. Playing Rock.\n";
    return moves["Rock"];
  }
}
