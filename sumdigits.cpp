#include <iostream>
int digitsum(int n) {

  if (n/10 < 10) {
    return (n % 10) + (n / 10);
  }
  return n % 10 + digitsum(n/10);
}

int main() {

  std::cout << digitsum(12345) << "\n";
}
