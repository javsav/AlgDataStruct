#include "Move.h"

Move::Move(std::string move) {
  name = move;
}

std::string Move::getName() {
  return name;
}

char Move::checkWin(Move* move) {
  return wins[move->getName()];
}
