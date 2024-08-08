#include "EfficientTruckloads.h"

int EfficientTruckloads::numTrucks(int numCrates, int loadSize) {

  int loads[5000] = {0};

  // Base case (return 1 for each individual pile when load size is reached)
  if (numCrates <= loadSize) {
    return 1;
  }

  // Recursively divide the load in half until the load size is reached
  if (numCrates % 2 == 0) {
    if (loads[numCrates] != 0) {
      return loads[numCrates];
    } else {
      loads[numCrates] = numTrucks(numCrates/2, loadSize) + numTrucks(numCrates/2, loadSize);
      return loads[numCrates];
    }
  } 
  // For odd numbers divide load unevenly
  else {
    if (loads[numCrates] != 0) {
      return loads[numCrates];
    } else {
      loads[numCrates] = numTrucks(numCrates/2 + 1, loadSize) + numTrucks(numCrates/2, loadSize);
      return loads[numCrates];
    }
  }
  }

