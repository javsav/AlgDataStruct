#pragma once
#include "Move.h"
#include <string>
#include <unordered_map>

class Player {
 
 protected:
  std::string name;
  std::string currentMove;
  std::unordered_map<std::string, Move*> moves;

 public:

  Player();

  Player(std::string name);
  
  void setName(std::string name);

  virtual Move* makeMove() = 0;  

  std::string getName();

};