#include "Finder.h"

#include <bits/stdc++.h>

#include <array>
#include <iostream>
#include <string>
#include <unordered_set>

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





std::vector<int> Finder::findSubstrings2(std::string s1, std::string s2) {
  size_t numPrefixes = s2.size();
  std::vector<long long> hashes(numPrefixes);
  std::vector<int> result(s2.size(), -1);
  const int base = 256;
  const int modulus = INT_MAX;
  long long power = 1;
 
  long long prefixHash = 0;
  long long textHash = 0;

  for (size_t i = 0; i < numPrefixes - 1; i++) {
    power = (power * base) % modulus;
  }

  for (size_t i = 0; i < numPrefixes; i++) {
    prefixHash = prefixHash + s2.c_str()[i];
    hashes[i] = prefixHash;
  }

  size_t left = 0;
  size_t right = 0;
  size_t lastIndex = 0;

  for (size_t strLength = 1; strLength <= numPrefixes; strLength++) {    

    left = right = lastIndex;
    textHash = 0;

    

    std::cout << "Strlength: " << strLength << "\n";
    while (right < s1.size()) {

      if (right - left <= strLength - 1) {
       textHash = textHash + (s1.c_str()[right++]);

      } 
      else {
        textHash = (textHash - s1.c_str()[left++] + s1.c_str()[right++]);
      }
      std::cout << "Text hash: " << textHash << ", Current substr hash: " << hashes[strLength - 1] << "\n";
      if (textHash == hashes[strLength - 1]) {
        result[strLength - 1] = left;
        lastIndex = right = left;
        break;
      }

      if (textHash < 0) {
        textHash = (textHash + modulus);
      }
    }
  }
  
  
  return result;
}


std::vector<int> Finder::findSubstrings3(std::string s1, std::string s2) {
  size_t numPrefixes = s2.size();
  const int base = 256;
  const int modulus = 1000000007;
  static long long hashVal = 0;
  static long long power = 1;
  std::vector<long long> hashes(numPrefixes);
  std::vector<int> result(s2.size(), -1);

  long long int hashArray[100] = {0};
  long long int modInverse[100] = {0};


  long long prefixHash = 0;
  long long textHash = 0;


  for (size_t i = 0; i < numPrefixes; i++) {
    prefixHash = (prefixHash + power * s2.c_str()[i]) % modulus;    
    power = (power * base) % modulus;
    hashes[i] = prefixHash;
  }

  size_t left = 0;
  size_t right = 0;
  size_t lastIndex = 0;
  long long powerStable;
  

  for (size_t strLength = 1; strLength <= numPrefixes; strLength++) {
    left = right = lastIndex;
    textHash = 0;
    power = 1;

    std::cout << "Strlength: " << strLength << "\n";
    while (right < s1.size()) {
      if (right - left < strLength) {
        textHash = (textHash + (power * s1.c_str()[right])) % modulus;
        hashArray[right] = textHash;
        modInverse[right++] = pow(power, modulus - 2);
        power = (power * base) % modulus;
        powerStable = power / base;
      } else {
        textHash -= hashArray[left];
        textHash = (textHash * modInverse[left++]) % modulus;
        textHash = (textHash + (powerStable * s1.c_str()[right])) % modulus;
        hashArray[right++] = textHash;
      }
      std::cout << "Text hash: " << textHash
                << ", Current substr hash: " << hashes[strLength - 1] << "\n";
      if (textHash == hashes[strLength - 1]) {
        result[strLength - 1] = left;
        lastIndex = right = left;
        break;
      }

      if (textHash < 0) {
        textHash = (textHash + modulus);
      }
    }
  }

  return result;
}

std::vector<int> Finder::findSubstrings4(std::string s1, std::string s2) {
  size_t numPrefixes = s2.size();
  const int base = 128;
  static long long hashVal = 0;
  static long long power = 1;
  std::vector<long long> hashes(numPrefixes);
  std::vector<int> result(s2.size(), -1);


  long long prefixHash = 0;
  long long textHash = 0;

  for (size_t i = 0; i < numPrefixes; i++) {
    prefixHash = (prefixHash + power * s2.c_str()[i]);
    power = (power * base);
    hashes[i] = prefixHash;
  }

  size_t left = 0;
  size_t right = 0;
  size_t lastIndex = 0;
  long long stablePower;
  for (size_t strLength = 1; strLength <= numPrefixes; strLength++) {
    left = right = lastIndex;
    textHash = 0;
    power = 1;
    std::cout << "Strlength: " << strLength << "\n";
    while (right < s1.size()) {
      if (right - left < strLength) {
        std::cout << "Right: " << right << ", Left: " << left << "\n";
        textHash = (textHash + (power * s1.c_str()[right++]));
        power = (power * base);
        stablePower = power / base;
      } else {
        
        textHash = textHash - s1.c_str()[left++];
        textHash = textHash / base;
        textHash = (textHash + (stablePower * s1.c_str()[right++]));
      }
      std::cout << "Text hash: " << textHash
                << ", current substr hash: "
                << hashes[strLength - 1] << "\n";
      if (textHash == hashes[strLength - 1]) {
        result[strLength - 1] = left;
        lastIndex = right = left;
        break;
      }

    }
  }

  return result;
}

int main() {

  std::string str1 = "1112112812212822128812821325821";
  std::string str2 = "12821325";
  Finder finder;

  std::vector<int> answer = finder.findSubstrings4(str1, str2);

  for (auto str: answer) {
    std::cout << str << "\n";
  }

}