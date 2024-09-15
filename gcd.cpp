#include <iostream>

int gcd(int a, int b) {

  while (b != 0) {
    std::cout << "a: " << a << " , b: " << b << "\n";
    int remainder = a % b;
    std::cout << "remainder: " << remainder << "\n";
    a = b;
    b = remainder;
  }
  std::cout << "GCD: " << a << "\n";
  return a;
}

int main() {
  gcd(12, 17);
}