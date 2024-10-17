#include <chrono>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>
#include <thread>

double powe(double x, long n) {
  // Edge case
  if (n == 0) {
    return 1;
  }
  // Base case
  if (n == 1) {
    return x;
  }
  // Negative powers
  if (n < 0) {
    x = 1 / x;
    n *= -1;
  }

  if (n % 2 == 0) {
    return powe(x*x, n/2);
  } else {
    return x * powe(x*x, n/2);
  }    
}

double myPow(double x, int n) {
  return powe(x, n);
}
int main() {
  int n = 100000;

  using std::chrono::duration;
  using std::chrono::duration_cast;
  using std::chrono::high_resolution_clock;
  using std::chrono::milliseconds;

  auto t1 = high_resolution_clock::now();
  for (int i = 0; i < n; i++) {
    double a = myPow(3, i);
  }
  auto t2 = high_resolution_clock::now();

  /* Getting number of milliseconds as an integer. */
  auto ms_int = duration_cast<milliseconds>(t2 - t1);

  /* Getting number of milliseconds as a double. */
  duration<double, std::milli> ms_double = t2 - t1;

  std::cout << ms_int.count() << "ms\n";
  std::cout << ms_double.count() << "ms\n";
}