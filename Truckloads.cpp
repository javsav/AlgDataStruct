#include "Truckloads.h"
#include <iostream>

int Truckloads::numTrucks(int numCrates, int loadSize) {

  // Base case (return 1 for each individual pile when load size is reached)
  if (numCrates <= loadSize) {
    return 1;
  }
  
  // Recursively divide the load in half until the load size is reached
  return numTrucks(numCrates/2, loadSize) + numTrucks(numCrates/2, loadSize);

}