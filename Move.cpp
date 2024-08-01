#include "Move.h"

// Parameterised constructor allows easy move setup //
Move::Move(std::string move, std::initializer_list<std::string> wins)
    : name(move), winsAgainst(wins) {}

std::string Move::getName() { return name; }

// Checks whether the opposing move is in the win list //
Move* Move::checkWinner(Move* other) {
  if (winsAgainst.count(other->getName())) {
    return this;
  } else if (this->name == other->getName()) {
    return nullptr;
  } else {
    return other;
  }
}
