#pragma once

#include <string>

class Player {
 
 protected:
  std::string name;
  char currentMove;

 public:
  Player();

  Player(std::string name);

  void setName(std::string name);

  virtual char makeMove() = 0;

  char getMove();

  std::string getName();
  
};