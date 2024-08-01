#include "Move.h"
#include "Rock.h"

Move::Move(std::string move) : name(move) {}

std::string Move::getName() {
  return name;
}

/*Move* Move::checkWin(Move* move1, Move* move2) {
  
  if (move1->getName() == move2->getName()) {
    return nullptr;
  } else if (moves[move1->getName()].count(move2->getName())) {
    return move1;
  } else {
    return move2;
  }
  
}*/

/*Move* Move::checkWin(Move* other) {
  
  if (this->name == other->getName()) {
    return nullptr;
  } else if (moves[this->name].count(other->getName())) {
    return this;
  } else {
    return other;
  }
  
}*/

Move* Move::checkWin(Move* other) {
  
  if (wins.count(other->getName())) {
    return this;
  } else if (this->name == other->getName()) {
    return nullptr;
  } else {
    return other;
  }
  
}

// Contains the moves which the key move beats
std::unordered_map<std::string, std::unordered_set<std::string>> Move::moves = {
  
  {"Monkey", {"Robot", "Ninja"}},
  {"Robot", {"Ninja", "Zombie"}},
  {"Ninja", {"Pirate", "Zombie"}},
  {"Pirate", {"Monkey", "Robot"}},
  {"Zombie", {"Monkey", "Pirate"}},

  {"Rock", {"Scissors"}},
  {"Paper", {"Rock"}},
  {"Scissors", {"Paper"}}
  
};
