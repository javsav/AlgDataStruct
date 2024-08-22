#include "Finder.h"

std::vector<int> Finder::findSubstrings(std::string s1, std::string s2) {
  
  std::vector<int> result(s2.size(), -1);
  
  size_t lastIndex = 0;
  
  for (size_t i = 1; i <= s2.size(); i++) {
    size_t found = s1.find(s2.substr(0, i), lastIndex);
    if (found != std::string::npos) {
      result[i - 1] = found;
      lastIndex = found;
    } else {
      break;
    }
  }
  return result;
}
