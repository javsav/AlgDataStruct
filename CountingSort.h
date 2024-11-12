#include <vector>
#include <iostream>

class CountingSort {

 private:
  std::vector<int> cSort(std::vector<int>& list, int counts[], int min, int max);
 public:
 std::vector<int> countingSort(std::vector<int>& list, int min, int max);


};