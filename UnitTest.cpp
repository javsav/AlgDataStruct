#include "Truckloads.h"
#include "Reverser.h"
#include "EfficientTruckloads.h"
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

  namespace ReverseStringTests {

    std::string str;

    bool testOne() {

      str = "HowDoYouDo";
      
      std::cout << "String in reverse: " << Reverser::reverseString(str) << ".\n";
      std::string revStr = str;
      std::reverse(revStr.begin(), revStr.end());
      return Reverser::reverseString(str) == revStr;

    }

    bool testTwo() {

      str = "RaCeCaR";
      
      std::cout << "String in reverse: " << Reverser::reverseString(str) << ".\n";
      std::string revStr = str;
      std::reverse(revStr.begin(), revStr.end());
      return Reverser::reverseString(str) == revStr;

    }

    bool testThree() {

      str = "Evian";
      
      std::cout << "String in reverse: " << Reverser::reverseString(str) << ".\n";
      std::string revStr = str;
      std::reverse(revStr.begin(), revStr.end());
      return Reverser::reverseString(str) == revStr;

    }

    bool testFour() {

      str = "X";
      
      std::cout << "String in reverse: " << Reverser::reverseString(str) << ".\n";
      std::string revStr = str;
      std::reverse(revStr.begin(), revStr.end());
      return Reverser::reverseString(str) == revStr;

    }

    bool testFive() {

      str = "Spacey    J A N E";
      
      std::cout << "String in reverse: " << Reverser::reverseString(str) << ".\n";
      std::string revStr = str;
      std::reverse(revStr.begin(), revStr.end());
      return Reverser::reverseString(str) == revStr;

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

  namespace EfficientTruckloadsTests {    
    
    int numCrates;
    int loadSize;    
   
    bool testOne() {

      numCrates = 24;
      loadSize = 3;
      
      std::cout << "Number of Trucks Required: " << EfficientTruckloads::numTrucks(numCrates, loadSize) << ".\n";

      return EfficientTruckloads::numTrucks(numCrates, loadSize) == 8;      

    }

    bool testTwo() {

      EfficientTruckloads::clearMemoizationCache();

      numCrates = 203;
      loadSize = 7;
      
      std::cout << "Number of Trucks Required: " << EfficientTruckloads::numTrucks(numCrates, loadSize) << ".\n";

      return EfficientTruckloads::numTrucks(numCrates, loadSize) == 32;      

    }

    bool testThree() {

      EfficientTruckloads::clearMemoizationCache();

      numCrates = 14;
      loadSize = 3;
      
      std::cout << "Number of Trucks Required: " << EfficientTruckloads::numTrucks(numCrates, loadSize) << ".\n";

      return EfficientTruckloads::numTrucks(numCrates, loadSize) == 6;      

    }

    bool testFour() {

      EfficientTruckloads::clearMemoizationCache();

      numCrates = 15;
      loadSize = 1;
      
      std::cout << "Number of Trucks Required: " << EfficientTruckloads::numTrucks(numCrates, loadSize) << ".\n";

      return EfficientTruckloads::numTrucks(numCrates, loadSize) == 15;      

    }

    bool testFive() {

      EfficientTruckloads::clearMemoizationCache();

      numCrates = 1024;
      loadSize = 5;
      
      std::cout << "Number of Trucks Required: " << EfficientTruckloads::numTrucks(numCrates, loadSize) << ".\n";

      return EfficientTruckloads::numTrucks(numCrates, loadSize) == 256;      

    }

    bool testSix() {

      EfficientTruckloads::clearMemoizationCache();

      numCrates = 7;
      loadSize = 2;
      
      std::cout << "Number of Trucks Required: " << EfficientTruckloads::numTrucks(numCrates, loadSize) << ".\n";

      return EfficientTruckloads::numTrucks(numCrates, loadSize) == 4;      

    }

    
  };

};

using namespace UnitTest;

// int main() {

//   runTest(TruckloadsTests::testOne);

//   runTest(TruckloadsTests::testTwo);

//   runTest(TruckloadsTests::testThree);

//   runTest(TruckloadsTests::testFour);

//   runTest(TruckloadsTests::testFive);

//   runTest(TruckloadsTests::testSix);

//   runTest(ReverseDigitTests::testOne);

//   runTest(ReverseDigitTests::testTwo);

//   runTest(ReverseDigitTests::testThree);

//   runTest(ReverseDigitTests::testFour);

//   runTest(ReverseDigitTests::testFive);

//   runTest(ReverseStringTests::testOne);

//   runTest(ReverseStringTests::testTwo);

//   runTest(ReverseStringTests::testThree);

//   runTest(ReverseStringTests::testFour);

//   runTest(ReverseStringTests::testFive);

//   runTest(EfficientTruckloadsTests::testOne);

//   runTest(EfficientTruckloadsTests::testTwo);

//   runTest(EfficientTruckloadsTests::testThree);

//   runTest(EfficientTruckloadsTests::testFour);

//   runTest(EfficientTruckloadsTests::testFive);

//   runTest(EfficientTruckloadsTests::testSix);

// }
