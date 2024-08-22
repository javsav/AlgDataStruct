#include <cmath>
#include <iostream>

int main() {

  const char* str = "abcde";

  const int base = 256;
  long long power = 1;
  const int modulus = 101;

  long long hash = 0;

  for (size_t ch = 2; ch < 5; ch++) {
    hash = (str[ch] * power) + hash;
    power *= base;
  }

  long long shortHash = 0;

  power = 1;

  for (size_t ch = 3; ch < 5; ch++) {
    
    shortHash = (str[ch] * power) + shortHash;
    power *= base;
  }

  std::cout << "Hash: " << hash << " , shortHash: " << shortHash << "\n";

  long long newHash = hash;
  power = 1;
 
  newHash = newHash - (str[2]);
  newHash = (newHash / base);

  //newHash = ((newHash * base)) % modulus;

  std::cout << "newHash: " << newHash << "\n";


}