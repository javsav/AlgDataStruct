#include "Player.h"

Player::Player() : name("Human"), currentMove('R') {}

Player::Player(std::string name) : name(name), currentMove('R') {}

char Player::getMove() {
  return currentMove;
}

std::string Player::getName() {
  return name;
}

void Player::setName(std::string name) {
  this->name = name;
}