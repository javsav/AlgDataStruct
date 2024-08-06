#include <iostream>
int sum(int n) {

  if (n == 1) {
    return 1;
  }
  return n + sum(n - 1);
}

int main() {

  std::cout << sum(4) << "\n";
}
