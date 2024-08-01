#ifndef MOVE_H
#define MOVE_H

#include <initializer_list>
#include <string>
#include <unordered_set>

class Move {
 protected:
  std::string name;
  // List of moves that the move wins against //
  std::unordered_set<std::string> winsAgainst;

 public:
  Move(std::string move, std::initializer_list<std::string> wins);
  // Returns the winner of two moves, or nullptr for tie //
  Move* checkWinner(Move* other);
  std::string getName();
};

#endif  // MOVE_H