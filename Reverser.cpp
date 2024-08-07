#include "Reverser.h"
#include <iostream>
#include <cmath>

std::string Reverser::reverseString(std::string characters) {

  // Base case: one character remaining
  if (characters.size() == 1) {
    return characters;
  }

  // Create shortened string with the final character erased
  std::string shortened = characters;
  shortened.pop_back();

  // Concatenate the final character of the string with recursive calls on the shortened string
  return characters[characters.size() - 1] + reverseString(shortened);
}

int Reverser::reverseDigit(int value) {

  // Calculate number of digits in current value
  int powTen = 0;
  int tempValue = value;
  // Repeatedly divide by 10 while number >= 10
  while (tempValue >= 10); {
    tempValue /= 10;
    powTen++;
  }


  // Base case: value has two or less digits.
  if (value/10 < 10) {
    return ((value % 10) * 10) + (value / 10);
  }

  // Modulo 10 returns the final digit, multiply by the number of digits - 1 and continue recursively
  return ((value % 10) * pow(10, powTen) + reverseDigit(value/10));
}

