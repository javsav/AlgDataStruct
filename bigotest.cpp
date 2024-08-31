#include <iostream>

int main() {
  int sum = 0;
  int n = 80;
  for (int i = n / 2; i < n; i = i * 2) {
    std::cout << "i: " << i << "\n";
    sum++;
    for (int j = i; j < n; j++) {
    std::cout << "j: " << j << "\n";

      sum++;
    }
  }
  std::cout << sum << "\n";
}