#include "Player.h"

#include "Monkey.h"
#include "Ninja.h"
#include "Paper.h"
#include "Pirate.h"
#include "Robot.h"
#include "Rock.h"
#include "Scissors.h"
#include "Zombie.h"

Player::Player() : name("Human") {}

Player::Player(std::string name) : name(name) {}

std::string Player::getName() { return name; }

void Player::setName(std::string name) { this->name = name; }

Player::~Player() {
  // Delete dynamically allocated moves from heap //
  for (auto i = moves.begin(); i != moves.end(); ++i) {
    delete i->second;
  }

  moves.clear();
}

// Player-entered string is used as a key for the hashmap to return specific move //
std::unordered_map<std::string, Move*> Player::moves = {
    {"Rock", new Rock},     {"Paper", new Paper},  {"Scissors", new Scissors},

    {"Monkey", new Monkey}, {"Robot", new Robot},  {"Zombie", new Zombie},
    {"Ninja", new Ninja},   {"Pirate", new Pirate}};
