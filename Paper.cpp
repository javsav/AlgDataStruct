#include "Paper.h"

Paper::Paper() : Move("Paper") {
  wins["Scissors"] = 'L';
  wins["Rock"] = 'W';
  wins["Paper"] = 'T';

  wins["Monkey"] = 'T';
  wins["Robot"] = 'T';
  wins["Pirate"] = 'T';
  wins["Ninja"] = 'T';
  wins["Zombie"] = 'T';
}