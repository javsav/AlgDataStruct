#include "Scissors.h"

Scissors::Scissors() : Move("Scissors") {
  wins["Rock"] = 'L';
  wins["Paper"] = 'W';
  wins["Scissors"] = 'T';

  wins["Monkey"] = 'T';
  wins["Robot"] = 'T';
  wins["Pirate"] = 'T';
  wins["Ninja"] = 'T';
  wins["Zombie"] = 'T';
}