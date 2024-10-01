#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <bitset>

struct array_hash {
  inline std::size_t operator()(int v[2]) const {
    return std::hash<int>()(v[0]);
  }
};

class Fibonacci {

  public:
  int fibonacci(int n) {
    if (n <= 1) {
      return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
  }
  // std::unordered_map<int, int>& array
  int fibonacciMemoHelper(int n, std::unordered_set<int[2], array_hash>& array) {
    if (n <= 1) {
      return 1;
    }

    if (array.count({n})) {
      return array.find({n})[0];
    } else {
      array[n] = fibonacciMemoHelper(n - 1, array) + fibonacciMemoHelper(n - 2, array);
      return array[n];
    }
  }

  int fibonacciMemo(int n) {
    //std::unordered_map<int, int> array;
    std::unordered_set<int[2], array_hash> array;
    array.reserve(2200);
    //int array[2200] = {0};
    return fibonacciMemoHelper(n, array);
  }
};