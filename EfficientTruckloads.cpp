#include "EfficientTruckloads.h"
#include <iostream>

void EfficientTruckloads::clearMemoizationCache() {
  loads.fill(0);
}

int EfficientTruckloads::numTrucks(int numCrates, int loadSize) {

  // Base case (return 1 for each individual pile when load size is reached)
  if (numCrates <= loadSize) {
    return 1;
  }

  if (numCrates % 2 == 0) {
    // Check if result previously calculated
    if (loads[numCrates]) {
      return loads[numCrates];
    } else {
      // Recursively divide the load in half until the load size is reached
      loads[numCrates] = numTrucks(numCrates/2, loadSize) + numTrucks(numCrates/2, loadSize);
      return loads[numCrates];
    }
  } 
  // For odd numbers divide load unevenly
  else {
    // Check if result previously calculated
    if (loads[numCrates]) {
      return loads[numCrates];
    } else {
      loads[numCrates] = numTrucks(numCrates/2 + 1, loadSize) + numTrucks(numCrates/2, loadSize);
      return loads[numCrates];
    }
  } 

  }

  std::array<int, 5000> EfficientTruckloads::loads = {0};

