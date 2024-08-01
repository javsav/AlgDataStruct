#include "Move.h"
#include "Rock.h"

// Parameterised constructor allows easy move setup //
Move::Move(std::string move, std::initializer_list<std::string> wins) : name(move), wins(wins) {}

std::string Move::getName() {
  return name;
}

// Checks whether the opposing move is in the win list //
Move* Move::checkWin(Move* other) {
  
  if (wins.count(other->getName())) {
    return this;
  } else if (this->name == other->getName()) {
    return nullptr;
  } else {
    return other;
  }
  
}
