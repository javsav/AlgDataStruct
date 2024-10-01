#include <array>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct pairHash {
  std::size_t operator()(const std::pair<int, int>& p) const {
    auto h1 = std::hash<int>{}(p.first);
    auto h2 = std::hash<int>{}(p.second);

    return h1 ^ h2;
  }
};


struct vectorHash {
  std::size_t operator()(const std::vector<int>& v) const {
    size_t hash = 1;
    int base = 13;
    int power = 1;
    for (auto i = v.begin(); i != v.end(); ++i) {
      hash *= std::hash<int>()(*i) * power;
      power *= base;     
    }
    return hash;
  }
};

struct vectorEqual {
 public:
  bool operator()(const std::vector<int>& v1, const std::vector<int>& v2) const {
    vectorHash hasher;
    if (hasher(v1) == hasher(v2))
      return true;
    else
      return false;
  }
};

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
  std::unordered_set<int> candidateSet;
  std::unordered_set<std::vector<int>, vectorHash, vectorEqual> duplicates;
  std::unordered_map<int, std::array<int, 2>> combinations;
  for (auto number : candidates) {
    candidateSet.insert(number);
  }

  for (int i = 0; i < candidates.size() - 1; i++) {
    for (int j = i + 1; j < candidates.size(); j++) {
      combinations[candidates[i] + candidates[j]] = {std::min(candidates[i], candidates[j]), std::max(candidates[i], candidates[j])};
    }
  }

  std::unordered_set<std::pair<int, int>, pairHash> visited;
  std::vector<std::vector<int>> answer;
  for (size_t number = 0; number < candidates.size(); number++) {
    int sum = 0;
    int count = 0;
    std::vector<int> current;
    while (sum + candidates[number] <= target) {
      sum += candidates[number];
      count++;
      int difference = target - sum;
      for (int divisor = 1; divisor <= difference; divisor++) {
        if (difference % divisor == 0) {
          //  && (!visited.count({candidates[number], difference / divisor}))
          if (candidateSet.count(difference / divisor)) {  //&& (!visited.count({difference / divisor, candidates[number]})) && (!visited.count({candidates[number], difference / divisor}))
            visited.insert({difference / divisor, candidates[number]});
            int tempCount = count;
            while (count > 0) {
              current.push_back(candidates[number]);
              count--;
            }
            count = tempCount;
            for (int cnt = 0; cnt < divisor; cnt++) {
              current.push_back(difference / divisor);
            }
            if (!duplicates.count(current)) {              
              answer.push_back(current);
              duplicates.insert(current);
            }
            current.clear();
            // sum = 0;
            // count = 0;
          }
        }
      }      
      difference = target - sum;
      if (combinations.count(difference) && (!visited.count({difference, combinations[difference][0]}))) {
        visited.insert({difference, combinations[difference][0]});
        //visited.insert({difference, combinations[difference][1]});
        int tempCount = count;
        while (count > 0) {
          current.push_back(candidates[number]);
          count--;
        }
        count = tempCount;
        current.push_back(combinations[difference][0]);
        current.push_back(combinations[difference][1]);
        if (!duplicates.count(current)) {          
          answer.push_back(current);
          duplicates.insert(current);
        }
        current.clear();
        // sum = 0;
        // count = 0;
      
      }
     
    }
  }
  if (candidateSet.count(target)) {
    answer.push_back({target});
  }
  
  return answer;
}

int main() {
  std::vector<int> candidates = {7,3,2};
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

// for (int i = 0; i < candidates.size() - 1; i++) {
//   for (int j = i + 1; j < candidates.size(); j++) {
//     if (combinations.count(candidates[i] + candidates[j])) {
//       combinations[candidates[i] + candidates[j]][2] = candidates[i];
//       combinations[candidates[i] + candidates[j]][3] = candidates[j];
//     } else {
//       combinations[candidates[i] + candidates[j]] = {candidates[i], candidates[j]};
//     }
//   }
// }