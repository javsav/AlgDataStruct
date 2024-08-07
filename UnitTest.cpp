#include "Truckloads.h"
#include "Reverser.h"
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

  namespace ReverseDigitTests {

    int digits;

    bool testOne() {

      digits = 1337;
      
      std::cout << "Digits in reverse: " << Reverser::reverseDigit(digits) << ".\n";

      return Reverser::reverseDigit(digits) == 7331;

    }

  }

  namespace TruckloadsTests {    
    
    int numCrates;
    int loadSize;    
   
    bool testOne() {

      numCrates = 24;
      loadSize = 3;
      
      std::cout << "Number of Trucks Required: " << Truckloads::numTrucks(numCrates, loadSize) << ".\n";

      return Truckloads::numTrucks(numCrates, loadSize) == 8;      

    }

    bool testTwo() {

      numCrates = 203;
      loadSize = 7;
      
      std::cout << "Number of Trucks Required: " << Truckloads::numTrucks(numCrates, loadSize) << ".\n";

      return Truckloads::numTrucks(numCrates, loadSize) == 32;      

    }

    bool testThree() {

      numCrates = 14;
      loadSize = 3;
      
      std::cout << "Number of Trucks Required: " << Truckloads::numTrucks(numCrates, loadSize) << ".\n";

      return Truckloads::numTrucks(numCrates, loadSize) == 6;      

    }

    bool testFour() {

      numCrates = 15;
      loadSize = 1;
      
      std::cout << "Number of Trucks Required: " << Truckloads::numTrucks(numCrates, loadSize) << ".\n";

      return Truckloads::numTrucks(numCrates, loadSize) == 15;      

    }

    bool testFive() {

      numCrates = 1024;
      loadSize = 5;
      
      std::cout << "Number of Trucks Required: " << Truckloads::numTrucks(numCrates, loadSize) << ".\n";

      return Truckloads::numTrucks(numCrates, loadSize) == 256;      

    }

    bool testSix() {

      numCrates = 7;
      loadSize = 2;
      
      std::cout << "Number of Trucks Required: " << Truckloads::numTrucks(numCrates, loadSize) << ".\n";

      return Truckloads::numTrucks(numCrates, loadSize) == 4;      

    }

    
  };

};

using namespace UnitTest;

int main() {

  runTest(TruckloadsTests::testOne);

  runTest(TruckloadsTests::testTwo);

  runTest(TruckloadsTests::testThree);

  runTest(TruckloadsTests::testFour);

  runTest(TruckloadsTests::testFive);

  runTest(TruckloadsTests::testSix);

  runTest(ReverseDigitTests::testOne);


}