#include <iostream>

int main() {
  int sum = 0;
  int n = 20;

  for (int i = 0; i < n; i++) {
    std::cout << "i: " << i << "\n";
    for (int j = 0; j < i; j++) {
      std::cout << "j: " << j << "\n";
      for (int k = 0; k < i; k++) {
        std::cout << "k: " << k << "\n";

        sum++;
      }
    }
  }
}