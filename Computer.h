#pragma once

#include "Player.h"
#include <string>

class Computer: public Player {

  private:

  char currentMove = 'R';
  std::string name = "Computer";

  public:

  char makeMove();

};