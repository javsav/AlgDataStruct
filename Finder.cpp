#include "Finder.h"

// Conventional Method
std::vector<int> Finder::findSubstrings2(std::string& s1, std::string& s2) {
  
  std::vector<int> result(s2.size(), -1);
  
  size_t lastIndex = 0;
  
  for (size_t i = 1; i <= s2.size(); i++) {
    // Prevent repeated checks of already matched characters
    if (s1[lastIndex + i - 1] == s2[i - 1]) {
      result[i - 1] = lastIndex;
      continue;

    } else {
      size_t found = s1.find(s2.substr(0, i), lastIndex + 1);
    
    if (found != std::string::npos) {
      result[i - 1] = found;
      lastIndex = found;
    } else {
      break;
    }

    }
        
    
  }
  return result;
}

// Method using rolling polynomial hash
std::vector<int> Finder::findSubstrings(std::string& s1, std::string& s2) {
 
  size_t numPrefixes = s2.size();
  const int base = 128;
  long long power = 1;
  long long prefixHash = 0;
  long long textHash = 0;
  
  std::vector<long long> hashes(numPrefixes);
  std::vector<int> result(s2.size(), -1);  

  for (size_t i = 0; i < numPrefixes; i++) {
    prefixHash = (prefixHash + power * s2.c_str()[i]);
    power = (power * base);
    hashes[i] = prefixHash;
  }

  size_t left = 0;
  size_t right = 0;
  size_t lastIndex = 0;

  for (size_t strLength = 1; strLength <= numPrefixes; strLength++) {
    left = right = lastIndex;
    textHash = 0;
    power = 1;
    while (right < s1.size()) {
      if (right - left < strLength) {        
        textHash = (textHash + (power * s1.c_str()[right++]));
        power = (power * base);

      } else {        
        textHash = textHash - s1.c_str()[left++];
        textHash = textHash / base;
        textHash = (textHash + ((power / base) * s1.c_str()[right++]));
      }
      
      if (textHash == hashes[strLength - 1]) {
        result[strLength - 1] = left;
        lastIndex = right = left;
        break;
      }

    }
  }

  return result;
}

/*int main() {

  std::string str1 = "1112112812212822128812821325821";
  std::string str2 = "12821325";
  Finder finder;

  std::vector<int> answer = finder.findSubstrings2(str1, str2);

  for (auto str: answer) {
    std::cout << str << "\n";
  }

}*/