#include <bits/stdc++.h>


using std::cout;

void func(int* arr, int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << *((arr + i * n) + j) << " ";
    }
    cout << std::endl;
  }
}

int main() {
  int m = 3, n = 3;
  int arr[m][n] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  func((int*)arr, m, n);
  return 0;
}