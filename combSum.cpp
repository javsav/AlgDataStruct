#include <array>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>


void combSumHelper(std::vector<int>& candidates, std::vector<std::vector<int>>& answer, std::vector<int>& current, int target, int index) {

  if (target == 0) {
    answer.push_back(current);
    return;
  }

  for (int i = index; i < candidates.size(); i++) {
    if (candidates[i] > target) {
      continue;
    }
    current.push_back(candidates[i]);
    combSumHelper(candidates, answer, current, target - candidates[i], i);
    current.pop_back();
  } 
}


std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
  std::vector<std::vector<int>> answer;
  std::vector<int> current;

  combSumHelper(candidates, answer, current, target, 0);
  
  return answer;
}

int main() {
  std::vector<int> candidates = {7, 3, 2};
  int target = 18;
  std::vector<std::vector<int>> ans = combinationSum(candidates, target);

  for (auto vec : ans) {
    for (auto num : vec) {
      std::cout << num << ", ";
    }
    std::cout << "\n";
  }
  // vectorHash hasher;
  // std::vector<int> h1 = {3, 3, 2, 2, 2, 2, 2, 2};
  // std::vector<int> h2 = {3, 3, 3, 3, 2, 2, 2};
  // std::cout << hasher(h1) << "\n";
  // std::cout << hasher(h2) << "\n";
}