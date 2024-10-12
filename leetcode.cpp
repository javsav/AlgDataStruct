#include <chrono>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>
#include <thread>

int divide(int dividend, int divisor) {
  bool isAltered = false;
  if (abs(divisor) > abs(dividend)) {
    return 0;
  } else if (dividend == divisor) {
    return 1;
  }
  if (dividend == std::numeric_limits<int>::max()) {
    if (divisor == 1) {
      return std::numeric_limits<int>::max();
    } else if (divisor == -1) {
      return std::numeric_limits<int>::min() + 1;
    }
    dividend = dividend - abs(divisor);
    isAltered = true;
  }
  if (dividend == std::numeric_limits<int>::min()) {
    if (divisor == 1) {
      return std::numeric_limits<int>::min();
    } else if (divisor == -1) {
      return std::numeric_limits<int>::max();
    }
    dividend = dividend + abs(divisor);
    isAltered = true;
  }
  if (divisor == 1) {
    return dividend;
  } else if (divisor == -1) {
    return -dividend;
  }
  int multiplier = 1;
  if ((divisor < 0 && dividend > 0) || (divisor > 0 && dividend < 0)) {
    multiplier = -1;
  }

  dividend = abs(dividend);
  divisor = abs(divisor);
  int quotient = exp(log(dividend) - log(divisor)) + 0.0000000001;
  if (isAltered) {
    quotient += 1;
  }
  if (multiplier == 1) {
    return quotient;
  } else {
    return -quotient;
  }
}
std::string countAndSayHelper(int n, int current, std::string& RLE) {
  if (current == n) {
    return RLE;
  }

  std::string newRLE;
  size_t ch = 0;

  while (ch < RLE.size()) {
    size_t charCount = 0;
    char current = RLE[ch];
    while (RLE[ch] == current) {
      ch++;
      charCount++;
    }
    newRLE += (charCount + '0');
    newRLE += current;
  }

  return countAndSayHelper(n, current + 1, newRLE);
}
std::string countAndSay(int n) {
  if (n == 1) {
    return "1";
  }
  std::string RLE = "1";

  return countAndSayHelper(n, 1, RLE);
}

int main() {
  int n = 50;

  using std::chrono::duration;
  using std::chrono::duration_cast;
  using std::chrono::high_resolution_clock;
  using std::chrono::milliseconds;

  auto t1 = high_resolution_clock::now();
  for (int i = 0; i < 100; i++) {
    countAndSay(n);
  }
  auto t2 = high_resolution_clock::now();

  /* Getting number of milliseconds as an integer. */
  auto ms_int = duration_cast<milliseconds>(t2 - t1);

  /* Getting number of milliseconds as a double. */
  duration<double, std::milli> ms_double = t2 - t1;

  std::cout << ms_int.count() << "ms\n";
  std::cout << ms_double.count() << "ms\n";
  return 0;
}

std::string countAndSayHelper(int n, int current, std::string& RLE) {
  if (current == n) {
    return RLE;
  }

  std::string newRLE;
  size_t ch = 0;

  while (ch < RLE.size()) {
    size_t charCount = 0;
    char current = RLE[ch];
    while (RLE[ch] == current) {
      ch++;
      charCount++;
    }
    newRLE += (charCount + '0');
    newRLE += current;
  }

  return countAndSayHelper(n, current + 1, newRLE);
}

std::string countAndSay(int n) {
  if (n == 1) {
    return "1";
  }

  std::string RLE = "1";
  return countAndSayHelper(n, 1, RLE);
}
