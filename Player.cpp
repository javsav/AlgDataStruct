#include "Player.h"
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"
#include "Monkey.h"
#include "Robot.h"
#include "Zombie.h"
#include "Ninja.h"
#include "Pirate.h"

Player::Player() : name("Human"), currentMove("Rock") {
  moves["Rock"] = new Rock;
  moves["Paper"] = new Paper;
  moves["Scissors"] = new Scissors;
  moves["Monkey"] = new Monkey;
  moves["Robot"] = new Robot;
  moves["Zombie"] = new Zombie;
  moves["Ninja"] = new Ninja;
  moves["Pirate"] = new Pirate;
}

Player::Player(std::string name) : name(name), currentMove("Rock") {
  moves["Rock"] = new Rock;
  moves["Paper"] = new Paper;
  moves["Scissors"] = new Scissors;
  moves["Monkey"] = new Monkey;
  moves["Robot"] = new Robot;
  moves["Zombie"] = new Zombie;
  moves["Ninja"] = new Ninja;
  moves["Pirate"] = new Pirate;
}

std::string Player::getName() {
  return name;
}

void Player::setName(std::string name) {
  this->name = name;
}