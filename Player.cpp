#include "Player.h"

Player::Player() : name("default"), currentMove('N') {}

Player::Player(std::string name) : name(name), currentMove('N') {}

char Player::getMove() {
  return currentMove;
}

std::string Player::getName() {
  return name;
}