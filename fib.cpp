#include <iostream>

int fibonacci(int n) {

  if (n <= 1) {
    return n;
  }
  std::cout << "n - 1: " << n - 1 << "\n" << "n - 2: " << n - 2 << "\n" << "n - 1 + n - 2 : " << n - 1 + n - 2 << "\n";
  return fibonacci(n - 1) + fibonacci(n - 2);

  // 0, 1, 1, 2, 3, 5, 8, 13, 21

}

int factorial(int n) {

  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }



}

int main() {
  std::cout << fibonacci(7) << "\n";
}
