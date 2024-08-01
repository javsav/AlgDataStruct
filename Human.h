#pragma once

#include "Player.h"
#include <iostream>

class Human: public Player {

  public:

  // Inherit constructors //
  using Player::Player;
  Move* makeMove();

};