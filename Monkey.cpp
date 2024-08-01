#include "Monkey.h"

Monkey::Monkey() : Move("Monkey") {
  wins["Scissors"] = 'T';
  wins["Rock"] = 'T';
  wins["Paper"] = 'T';
  
  wins["Monkey"] = 'T';
  wins["Robot"] = 'W';
  wins["Pirate"] = 'L';
  wins["Ninja"] = 'W';
  wins["Zombie"] = 'L';

}