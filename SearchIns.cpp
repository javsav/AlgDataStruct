#include <vector>
#include <cstdlib>
#include <iostream>

int searchInsert(std::vector<int>& nums, int target) {
  int insPos = 0;

  int len = nums.size();
  int start = 0;
  int end = len - 1;
  int mid = (start + end) / 2;
  int diff = 1000;
  int placeholder = 0;
  int minIndx = 0;

  while (start <= end) {
    if (nums[mid] == target) {
      return mid;
    }

    if (abs(target - nums[mid]) < diff) {
      diff = abs(target - nums[mid]);
      minIndx = mid;
      placeholder = nums[mid];
    }

    if (nums[mid] < target) {
      start = mid + 1;
      mid = (start + end) / 2;
    } else {
      end = mid - 1;
      mid = (start + end) / 2;
    }

  }
  if (target > placeholder) {
    minIndx++;
  }
  return minIndx;
}

int main() {
  std::vector<int> nums = {1,3,5,6};
  int target = 7;
  std::cout << searchInsert(nums, target) << "\n";
}
