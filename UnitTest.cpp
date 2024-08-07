#include "Truckloads.h"
#include <iostream>

namespace Test {
  auto Trucks = Truckloads::numTrucks(numCrates, loadSize);
}

class UnitTest {
  
  public:

  class TruckloadsTests {

    private:

    int numCrates;
    int loadSize;
    
    public:
    
    bool TestOne() {

      numCrates = 24;
      loadSize = 3;
      
      std::cout << Test::Trucks << "\n";

      return Test::Trucks == numCrates/loadSize;      

    }

    
  };

};