#include "Ninja.h"

Ninja::Ninja() : Move("Ninja") {
  wins["Scissors"] = 'T';
  wins["Rock"] = 'T';
  wins["Paper"] = 'T';
  
  wins["Monkey"] = 'L';
  wins["Robot"] = 'L';
  wins["Pirate"] = 'W';
  wins["Ninja"] = 'T';
  wins["Zombie"] = 'W';

}