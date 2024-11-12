#include "CountingSort.h"



std::vector<int> CountingSort::cSort(std::vector<int>& list, int counts[], int min, int max)
{
  std::vector<int> sortedList(list.size());  
  for (int i = list.size() - 1; i >= 0; i--) {
    if (counts[list[i] - min] >= 0) {
      sortedList[counts[list[i] - min] - 1] = list[i];
      counts[list[i] - min]--;
    }
  }
  return sortedList;
}

std::vector<int> CountingSort::countingSort(std::vector<int>& list, int min, int max)
{
  int range = (max - min) + 1;
  int counts[range] {{}};
  int cumsum[range] {{}};
  for (int i = 0; i < list.size(); i++) {
    counts[list[i] - min]++;
  }  
  int sum = 0;
  for (int i = 0; i < range; i++) {
    cumsum[i] = counts[i] + sum;
    sum += counts[i];
  }
  std::vector<int> slist = cSort(list, cumsum, min, max);
  return slist;
}

int main() {
  CountingSort c;
  std::vector<int> list = {4,5,8,7,4,6,9,8,4,5};
  std::vector<int> newList = c.countingSort(list, 4, 9);

  for (auto num:newList) {
    std::cout << num << ' ';
  }
  std::cout << '\n';
}

