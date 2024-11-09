#include <bits/stdc++.h>

int stairs(int n, int arr[]) {  
  if (n <= 1) {
    return 1;
  }
  if (arr[n]) {
    return arr[n];
  } else {
    arr[n] = stairs(n - 1, arr) + stairs(n - 2, arr);
    return arr[n];
  }
}

int climbStairs(int n) {
  int array[n + 1];
  std::memset(array, 0, sizeof array);
  return stairs(n, array);
}

int main() {
  std::cout << "indeed: " << climbStairs(10);
}