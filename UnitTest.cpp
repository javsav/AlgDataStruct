#include "Truckloads.h"
#include "Reverser.h"
#include <iostream>
#include <algorithm>

namespace UnitTest {

  static int num = 1;

  void test() {
    std::cout << "Test: " << num << "\n";
    num++;
  } 

  void runTest(bool (*function)()) {
    test();

    if (function()) {
      std::cout << "Test Passed.\n\n";
    } else {
      std::cout << "Test Failed.\n\n";
    }

  }

  namespace ReverseDigitTests {

    int digits;

    bool testOne() {

      digits = 1337;
      
      std::cout << "Digits in reverse: " << Reverser::reverseDigit(digits) << ".\n";
      std::string digit = std::to_string(digits);
      std::reverse(digit.begin(), digit.end());
      return Reverser::reverseDigit(digits) == stoi(digit);

    }

    bool testTwo() {

      digits = 0;
      
      std::cout << "Digits in reverse: " << Reverser::reverseDigit(digits) << ".\n";
      std::string digit = std::to_string(digits);
      std::reverse(digit.begin(), digit.end());
      return Reverser::reverseDigit(digits) == stoi(digit);

    }

    bool testThree() {

      digits = 10;
      
      std::cout << "Digits in reverse: " << Reverser::reverseDigit(digits) << ".\n";
      std::string digit = std::to_string(digits);
      std::reverse(digit.begin(), digit.end());
      return Reverser::reverseDigit(digits) == stoi(digit);

    }

    bool testFour() {

      digits = 999979979;
      
      std::cout << "Digits in reverse: " << Reverser::reverseDigit(digits) << ".\n";
      std::string digit = std::to_string(digits);
      std::reverse(digit.begin(), digit.end());
      return Reverser::reverseDigit(digits) == stoi(digit);

    }

    bool testFive() {

      digits = 123456789;
      
      std::cout << "Digits in reverse: " << Reverser::reverseDigit(digits) << ".\n";
      std::string digit = std::to_string(digits);
      std::reverse(digit.begin(), digit.end());
      return Reverser::reverseDigit(digits) == stoi(digit);

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

  runTest(ReverseDigitTests::testTwo);

  runTest(ReverseDigitTests::testThree);

  runTest(ReverseDigitTests::testFour);

  runTest(ReverseDigitTests::testFive);


}