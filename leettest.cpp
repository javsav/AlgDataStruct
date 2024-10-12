#include <chrono>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>
#include <thread>
#include <vector>
#include <algorithm>

void combSumHelper(std::vector<int>& candidates, std::vector<std::vector<int>>& answer, std::vector<int>& current, int target, int index) {
             
  if (target == 0) {
    answer.push_back(current);
    return;
  }

  if (candidates[index] > target) {
    return;
  }

  for (int i = index; i < candidates.size(); i++) {
    if (i > index && candidates[i] == candidates[i - 1]) {
      continue;
    }

    current.push_back(candidates[i]);

    combSumHelper(candidates, answer, current, target - candidates[i], i + 1);
    current.pop_back();
  }
}

std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {                                              
  std::vector<std::vector<int>> answer;
  std::vector<int> current;
  std::sort(candidates.begin(), candidates.end());

  combSumHelper(candidates, answer, current, target, 0);

  return answer;
}

int main () {
  int n = 10000;
  std::vector<int> nums = {2,5,2,1,2};
  int target = 5;
  using std::chrono::duration;
  using std::chrono::duration_cast;
  using std::chrono::high_resolution_clock;
  using std::chrono::milliseconds;

  auto t1 = high_resolution_clock::now();
  for (int i = 0; i < n; i++) {
    combinationSum2(nums, target);
  }
  auto t2 = high_resolution_clock::now();

  /* Getting number of milliseconds as an integer. */
  auto ms_int = duration_cast<milliseconds>(t2 - t1);

  /* Getting number of milliseconds as a double. */
  duration<double, std::milli> ms_double = t2 - t1;

  std::cout << ms_int.count() << "ms\n";
  std::cout << ms_double.count() << "ms\n";
  return 0;
}