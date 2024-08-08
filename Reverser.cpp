#include "Reverser.h"
#include <iostream>
#include <cmath>

std::string Reverser::reverseString(std::string characters) {

  // Input validation
  if (characters.empty()) {
    return "ERROR";
  }
  
  // Base case: one character remaining
  if (characters.size() == 1) {
    return characters;
  }

  // Concatenate the final character of the string with recursive calls on the string without the last character
  return characters[characters.size() - 1] + reverseString(characters.substr(0, characters.size() - 1));
}

int Reverser::reverseDigit(int value) {
  // Handle invalid input
  if (value < 0) {
    return -1;
  }

  // Calculate number of digits in current value
  int powTen = 0;
  int tempValue = value;
  // Repeatedly divide by 10 while number >= 10
  while (tempValue >= 10) {
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

