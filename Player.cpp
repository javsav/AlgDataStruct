#include "Player.h"

Player::Player() : name("Human"), currentMove('N') {}

Player::Player(std::string name) : name(name), currentMove('N') {}

char Player::getMove() {
  return currentMove;
}

std::string Player::getName() {
  return name;
}

void Player::setName(std::string name) {
  this->name = name;
}