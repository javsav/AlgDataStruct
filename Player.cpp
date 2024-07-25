#include "Player.h"

Player::Player() : name("default") {}

Player::Player(std::string name) : name(name) {}

std::string Player::getName() {
  return name;
}