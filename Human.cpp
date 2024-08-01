#include "Human.h"

Move* Human::makeMove() {
  std::string move;

  // Player enters move as a string //
  std::cout << "\nEnter move: ";
  std::cin >> move;
  std::cout << "\n";
  // Must match name exactly //
  if (moves.count(move)) {
    return moves[move];
  }
  // Else, rock is played //
  else {
    std::cout << "Invalid move. Playing Rock.\n";
    return moves["Rock"];
  }
}
