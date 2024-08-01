#include "Move.h"
#include "Rock.h"

Move::Move(std::string move, std::initializer_list<std::string> wins) : name(move), wins(wins) {}

std::string Move::getName() {
  return name;
}

Move* Move::checkWin(Move* other) {
  
  if (wins.count(other->getName())) {
    return this;
  } else if (this->name == other->getName()) {
    return nullptr;
  } else {
    return other;
  }
  
}
