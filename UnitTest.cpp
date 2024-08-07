#include "Truckloads.h"
#include <iostream>

namespace UnitTest {

  static int num = 1;

  void test() {
    std::cout << "Test: " << num << "\n";
    num++;
  } 

  void runTest(bool (*function)()) {
    test();

    if (function()) {
      std::cout << "Test Passed.\n";
    } else {
      std::cout << "Test Failed.\n";
    }

  }

  namespace TruckloadsTests {    
    
    int numCrates;
    int loadSize;    
   
    bool testOne() {

      numCrates = 24;
      loadSize = 3;
      
      std::cout << "Number of Trucks Required: " << Truckloads::numTrucks(numCrates, loadSize) << ".\n";

      return Truckloads::numTrucks(numCrates, loadSize) == numCrates/loadSize;      

    }

    bool testTwo() {

      numCrates = 203;
      loadSize = 7;
      
      std::cout << "Number of Trucks Required: " << Truckloads::numTrucks(numCrates, loadSize) << ".\n";

      return Truckloads::numTrucks(numCrates, loadSize) == numCrates/loadSize;      

    }

    bool testThree() {

      numCrates = 14;
      loadSize = 3;
      
      std::cout << "Number of Trucks Required: " << Truckloads::numTrucks(numCrates, loadSize) << ".\n";

      return Truckloads::numTrucks(numCrates, loadSize) == numCrates/loadSize;      

    }

    
  };

};

using namespace UnitTest;

int main() {

  runTest(TruckloadsTests::testOne);

  runTest(TruckloadsTests::testTwo);

  runTest(TruckloadsTests::testThree);


}