#pragma once

#include <string>
#include <unordered_map>

class Move {

  protected:
  
  std::string name;
  std::unordered_map<std::string, char> wins;

  public:

  Move(std::string move);
  char checkWin(Move* move);
  std::string getName();


};