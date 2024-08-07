#include "Truckloads.h"
#include <iostream>

namespace UnitTest {  

  namespace TruckloadsTests {    
    
    int numCrates;
    int loadSize;
    auto LoadTest = Truckloads::numTrucks(numCrates, loadSize);    
   
    bool testOne() {

      numCrates = 24;
      loadSize = 3;
      
      std::cout << LoadTest << "\n";

      return LoadTest == numCrates/loadSize;      

    }

    
  };

};

int main() {

  std::cout << UnitTest::TruckloadsTests::testOne() << "\n";

}