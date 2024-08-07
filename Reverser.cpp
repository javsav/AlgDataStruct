#include "Reverser.h"
#include <cmath>

std::string Reverser::reverseString(std::string characters) {

  if (characters.size() == 1) {
    return characters;
  }
  std::string temp = characters;
  temp.pop_back();
  return characters[characters.size() - 1] + reverseString(temp);
}

int Reverser::reverseDigit(int value) {

  std::string digits = std::to_string(value);
  int multiplier = digits.size() - 1;

  if (value/10 < 10) {
    return ((value % 10) * 10) + (value / 10);
  }
  return ((value % 10) * pow(10,multiplier) + reverseDigit(value/10));
}

