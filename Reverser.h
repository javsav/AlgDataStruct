#include <string>
#ifndef REVERSER_H
#define REVERSER_H

class Reverser {

  public:
  // Not static due to test interface
  static int reverseDigit(int value);

  static std::string reverseString(std::string characters);

};

#endif // REVERSER_H