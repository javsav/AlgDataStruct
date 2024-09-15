#include <iostream>
#include <cmath>

double factorial (double m) {
  double result = 1;

  while (m > 1) {
    result *= m;
    m--;
  }

  return result;
}

double fun1(double n) {
  double ivar, jvar, kvar, ovar;
  ivar = jvar = kvar = ovar = 0;
  // for (int i = 1; i <= n; i ++) {
  //   ivar++;
    for (int j = 1; j <= n; j*=2) {
      ovar++;
      for (int k = 1; k <= j; k++) {
        kvar++;
      }
    }
  //}
  
  std::cout << "outer: " << ivar << ", " << ivar/n << "\n";
  std::cout << "middle: " << ovar << ", " << ovar / n << "\n";
  std::cout << "inner: " << kvar << ", " << kvar / n << "\n";

  double lvar;
  ivar = jvar = lvar = 0;
  // for (int i = 1; i <= 2*n; i++) {
  //   ivar++;
    for (int j = 1; j <= 2*n; j*=2) {
      jvar++;
  for (int k = 1; k <= j; k++) {
    lvar++;
  }
    }
 // }
  
  std::cout << "outer: " << ivar << ", " << ivar / n << "\n";
  std::cout << "middle: " << jvar << ", " << jvar / n << "\n";
  std::cout << "inner: " << lvar << ", " << lvar / n << "\n";

  std::cout << "when n doubled, number of operations increased by: " << lvar/kvar << " times\n"; 

  return kvar/n;
}

int main() {
  std::cout << fun1(2400) << "\n";
  
}