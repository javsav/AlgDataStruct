#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>

class Move {

  protected:
  
  std::string name;
  static std::unordered_map<std::string, std::unordered_set<std::string>> moves;
  std::unordered_set<std::string> wins;
  
  public:

  Move(std::string move);
  Move* checkWin(Move* other);
  std::string getName();


};