#ifndef FINDER_H
#define FINDER_H
#include <chrono>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Finder {
 
 public:
  std::vector<int> findSubstrings(std::string& s1, std::string& s2);
  std::vector<int> findSubstrings2(std::string& s1, std::string& s2);
  
};

#endif
