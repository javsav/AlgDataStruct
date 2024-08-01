#pragma once

#include <string>
#include <unordered_set>
#include <initializer_list>

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