#pragma once

#include "Player.h"
#include <iostream>

class Human: public Player {

  public:

  using Player::Player;

  char makeMove();


};