#include <iostream>

int main() {
int n = 4;
int count = 0;
for (int i = 1; i <= n; i *= 2) {
  std::cout << "i: " << i << "\n";
    for (int j = 1; j <= n; j += i) {
     
        for (int k = 1; k <= j; k++) {
          std::cout << "k: " << k << "\n";
            count++;
        }
    }
}
}