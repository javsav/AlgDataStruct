#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

#include "Player.h"

class Computer : public Player {
 public:
  Computer();
  Move* makeMove();
};

#endif // COMPUTER_H