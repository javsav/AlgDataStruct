#include <string>
#include <iostream>

int main() {
  std::string test = "test";
  const char* test2 = test.c_str();
  std::cout << test2[3] << "\n";
  test = test + "apple";
  std::cout << test2[5] << "\n";
  test = test + "ppple";
  const char* a = &(test2[5]);
  std::cout << a[0] << "\n";
  test = test + "ppplepapplepapple";
  std::cout << a[0] << "\n";
  std::cout << test2[5] << "\n";
}

#include <array>
#include <iostream>
#include <string>
#include <unordered_set>

#include "Finder.h"

std::vector<int> Finder::findSubstrings(std::string& s1, std::string& s2) {
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

const int base = 256;
const int modulus = 1000000007;
static long long hashVal = 0;
static long long power = 1;

long long hashIncrease(const char* ch) {
  hashVal = (hashVal + ch[0] * power) % modulus;
  power = (power * base) % modulus;

  return hashVal;
}

long long hashStable(const char* ch) {
  hashVal = (hashVal + ch[0] * power) % modulus;
  return hashVal;
}

long long hashDecrease(const char* ch) {
  hashVal = (hashVal - ch[0] + modulus) % modulus;
  hashVal = (hashVal * base) % modulus;

  return hashVal;
}

std::vector<int> Finder::findSubstrings2(std::string& s1, std::string& s2) {
  size_t numPrefixes = s2.size();
  std::vector<long long> hashes(numPrefixes);
  std::vector<int> result(s2.size(), -1);

  size_t left = 0;
  size_t right = 0;
  long long hash = 0;
  while (right < numPrefixes) {
    hash += hashIncrease(&s2.c_str()[right]);
    hashes[right++] = hash;
  }

  right = 0;
  hashVal = 0;
  power = 1;
  hash = 0;
  size_t lastIndex = 0;

  for (size_t strLength = 1; strLength <= numPrefixes; strLength++) {
    left = right = lastIndex;
    hashVal = 0;
    power = 1;
    hash = 0;
    std::cout << "Strlength: " << strLength << "\n";
    while (right < s1.size()) {
      if (right - left <= strLength) {
        hash += hashIncrease(&s1.c_str()[right++]);
      } else {
        hash += hashStable(&s1.c_str()[right++]);
      }
      std::cout << "Text hash: " << hash
                << ", Current substr hash: " << hashes[strLength - 1] << "\n";
      if (hash == hashes[strLength - 1]) {
        result[strLength - 1] = left;
        lastIndex = right = left;
        hashVal = 0;
        power = 1;
        hash = 0;
        break;
      }

      if (right - left == strLength) {
        hash = hashDecrease(&s1.c_str()[left++]);
      }
    }
  }

  return result;
}

int main() {
  std::string str1 = "12322812839";
  std::string str2 = "12832";
  Finder finder;

  std::vector<int> answer = finder.findSubstrings2(str1, str2);

  for (auto str : answer) {
    std::cout << str << "\n";
  }
}