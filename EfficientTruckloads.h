#ifndef EFFICIENTTRUCKLOADS_H
#define EFFICIENTTRUCKLOADS_H
#include <array>

class EfficientTruckloads {
 
 public:

  static void clearMemoizationCache();
  static int numTrucks(int numCrates, int loadSize);
  static std::array<int, 5000> loads;
  
};

#endif  // TRUCKLOADS_H