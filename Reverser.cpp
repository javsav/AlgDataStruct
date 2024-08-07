#include "Reverser.h"

std::string Reverser::reverseString(std::string characters) {

  if (characters.size() == 1) {
    return characters;
  }
  std::string temp = characters;
  temp.pop_back();
  return characters[characters.size() - 1] + reverseString(temp);
}

int Reverser::reverseDigit(int value) {

  if (value/10 < 10) {
    return (value % 10) + (value / 10);
  }
  return ((value % 10) * 10) + reverseDigit(value/10);
}