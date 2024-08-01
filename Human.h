#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>

#include "Player.h"

class Human : public Player {
 public:
  // Inherit constructors //
  using Player::Player;
  Move* makeMove();
};

#endif  // HUMAN_H