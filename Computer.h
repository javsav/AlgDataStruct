#pragma once

#include "Player.h"
#include <string>

class Computer: public Player {

  public:
  
  Computer();
  Move* makeMove();

};