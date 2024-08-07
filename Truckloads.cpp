#include "Truckloads.h"

int Truckloads::numTrucks(int numCrates, int loadSize) {

  // Base case (return 1 for each individual pile when load size is reached)
  if (numCrates <= loadSize) {
    return 1;
  }

  // Recursively divide the load in half until the load size is reached
  if (numCrates % 2 == 0) {
    return numTrucks(numCrates/2, loadSize) + numTrucks(numCrates/2, loadSize);
  } 
  // For odd numbers divide load unevenly
  else {
    return numTrucks(numCrates/2 + 1, loadSize) + numTrucks(numCrates/2, loadSize);
  }

}