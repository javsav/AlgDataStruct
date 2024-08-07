#include "Reverser.h"

std::string Reverser::reverseString(std::string characters) {

  if (characters.size() == 1) {
    return characters;
  }
  std::string temp = characters;
  temp.pop_back();
  return characters[characters.size() - 1] + reverseString(temp);
}

