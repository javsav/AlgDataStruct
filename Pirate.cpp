#include "Pirate.h"

Pirate::Pirate() : Move("Pirate") {
  wins["Scissors"] = 'T';
  wins["Rock"] = 'T';
  wins["Paper"] = 'T';
  
  wins["Monkey"] = 'W';
  wins["Robot"] = 'W';
  wins["Pirate"] = 'T';
  wins["Ninja"] = 'L';
  wins["Zombie"] = 'L';

}