#include "Reverser.h"
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
  int numDigits = 0;
  // Repeatedly divide by 10 until number == 0
  do {
    value /= 10;
    numDigits++;
  } while (value != 0);

  // Base case: value has two digits.
  if (value/10 < 10) {
    return ((value % 10) * 10) + (value / 10);
  }
  
  // Modulo 10 returns the final digit, multiply by the number of digits and continue recursively
  return ((value % 10) * pow(10, numDigits) + reverseDigit(value/10));
}

