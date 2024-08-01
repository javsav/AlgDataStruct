#ifndef MOVE_H
#define MOVE_H

#include <initializer_list>
#include <string>
#include <unordered_set>

class Move {
 protected:
  std::string name;
  // List of moves that the move wins against //
  std::unordered_set<std::string> wins;

 public:
  Move(std::string move, std::initializer_list<std::string> wins);
  Move* checkWin(Move* other);
  std::string getName();
};

#endif  // MOVE_H