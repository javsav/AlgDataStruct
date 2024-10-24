#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <initializer_list>
#include <iostream>
#include <limits>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "nqueens2.cpp"

double anagramHash(std::string& str) {
  static constexpr int primes[26] = {2, 67, 23, 47, 3, 73, 71, 61, 5, 29, 31, 37, 41, 43, 7, 53, 59, 19, 13, 17, 11, 79, 83, 89, 97, 101};
  double hash = 1;
  for (int i = 0; i < str.size(); i++) {
    hash *= primes[str[i] - 'a'];
  }
  return hash;
}

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
  std::vector<std::vector<std::string>> answer;
  std::unordered_map<double, int> hashes;
  answer.reserve(strs.size());  
  int answerIdx = 1;
  for (int i = 0; i < strs.size(); i++) {    
    double hash = anagramHash(strs[i]);
    if (hashes[hash]) {
      answer[hashes[hash] - 1].push_back(strs[i]);
    } else {
      hashes[hash] = answerIdx;
      answer.emplace_back(std::initializer_list<std::string>{strs[i]});
      answerIdx++;
    }
  }
  return answer;
}

std::vector<std::vector<std::string>> groupAnagrams2(std::vector<std::string>& strs) {
  std::vector<std::vector<std::string>> answer;
  std::unordered_map<double, std::vector<std::string>> hashes;
  answer.reserve(strs.size());  
  for (int i = 0; i < strs.size(); i++) {    
    double hash = anagramHash(strs[i]);    
      hashes[hash].push_back(strs[i]);      
    }

  for (auto vec = hashes.begin(); vec != hashes.end(); vec++) {
    answer.push_back(vec->second);
  }
  
  return answer;
}


int main() {
  std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  int n = 1000;
  
  using std::chrono::duration;
  using std::chrono::duration_cast;
  using std::chrono::high_resolution_clock;
  using std::chrono::milliseconds;

  auto t1 = high_resolution_clock::now();
  for (int i = 0; i < n; i++) {
    std::vector<std::vector<std::string>> answers = solveNQueens(5);
  }
  auto t2 = high_resolution_clock::now();

  /* Getting number of milliseconds as an integer. */
  auto ms_int = duration_cast<milliseconds>(t2 - t1);

  /* Getting number of milliseconds as a double. */
  duration<double, std::milli> ms_double = t2 - t1;

  std::cout << ms_int.count() << "ms\n";
  std::cout << ms_double.count() << "ms\n";
  // std::vector<std::vector<std::string>> anagrams = groupAnagrams(strs);

  // for (auto vec:anagrams) {
  //   for (auto str:vec) {
  //     std::cout << str << ' ';
  //   }
  //   std::cout << '\n';
  // }
  // std::cout << '\n';
}