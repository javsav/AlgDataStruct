#include "Zombie.h"

Zombie::Zombie() : Move("Zombie") {
  wins["Scissors"] = 'T';
  wins["Rock"] = 'T';
  wins["Paper"] = 'T';
  
  wins["Monkey"] = 'W';
  wins["Robot"] = 'L';
  wins["Pirate"] = 'W';
  wins["Ninja"] = 'L';
  wins["Zombie"] = 'T';

}