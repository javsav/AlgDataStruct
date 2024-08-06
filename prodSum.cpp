#include <iostream>
// 1*2 + 2*3 + 3*4 + 4*5 + ... + (n-1) * n
int prodSum(int n) {

  if (n == 1) {
    return 0;
  }
  return n * (n - 1) + prodSum(n - 1);
}

int main() {

  std::cout << prodSum(20) << "\n";
}
