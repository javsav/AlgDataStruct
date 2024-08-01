#include "Rock.h"

Rock::Rock() : Move("Rock") {
  wins["Scissors"] = 'W';
  wins["Paper"] = 'L';
  wins["Rock"] = 'T';

  wins["Monkey"] = 'T';
  wins["Robot"] = 'T';
  wins["Pirate"] = 'T';
  wins["Ninja"] = 'T';
  wins["Zombie"] = 'T';
}