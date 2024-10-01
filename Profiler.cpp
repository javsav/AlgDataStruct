#include "Profiler.h"
#include "Fibonacci.cpp"
#include <thread>

void Profiler::profile(int runs, std::function<int(int)> func, int arg) {
  auto start = std::chrono::high_resolution_clock::now();

  for (int n = 0; n < runs; n++) {
    func(arg);
  }
  
  // int sum = 2;
  // for (int n = 0; n < 100; n++) {
  //   sum *= sum;
  // }

  // End the timer
  auto end = std::chrono::high_resolution_clock::now();

  // Calculate the duration
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

  // Print the duration in seconds
  std::cout << "Execution time: " << duration.count() << " ms." << std::endl;
}


int main() {
  Profiler p;
  Fibonacci fibo;
  auto func = (std::bind(&Fibonacci::fibonacciMemo, &fibo, std::placeholders::_1));
  p.profile(600, func, 2000);
}