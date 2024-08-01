#include "Robot.h"

Robot::Robot() : Move("Robot") {
  wins["Scissors"] = 'T';
  wins["Rock"] = 'T';
  wins["Paper"] = 'T';
  
  wins["Monkey"] = 'L';
  wins["Robot"] = 'T';
  wins["Pirate"] = 'L';
  wins["Ninja"] = 'W';
  wins["Zombie"] = 'W';

}