#include "Sort.h"
#include <limits>
#include <random>
#include <ctime>
#include <bits/stdc++.h>

void Sort::printList(std::vector<int>& list) {
  std::cout << "[";
  for (auto j = list.begin(); j != list.end(); ++j) {
    std::cout << *j << " ";
  }
  std::cout << "]\n";
}

std::vector<int>& Sort::selectionSort(std::vector<int>& list) {

  int n = list.size();

  size_t left = 0;
  while (left < n - 1) {
    int min = left;

    for (size_t right = left + 1; right < n; right++) {
      if (list[right] < list[min]) {
        min = right;
      }
    }
    std::swap(list[left++], list[min]);
  }

  return list;

}

std::vector<int>& Sort::insertionSortBasic(std::vector<int>& list) {

  int n = list.size();

  
  size_t right = 1;
  while (right < n) {    

    for (size_t left = right; left > 0; left--) {
      if (list[left] < list[left - 1]) {
        std::swap(list[left], list[left - 1]);
      } else {
        break;
      }
    }
    right++;
  }

  return list;

}

std::vector<int>& Sort::insertionSort(std::vector<int>& list) {
  int n = list.size();

  size_t right = 1;
  while (right < n) {
    int key = list[right];
    size_t left = right - 1;
    while (list[left] > key && left >= 0) {        
        list[left + 1] = list[left];
        left--;        
      }
    list[left + 1] = key;
    right++;
    std::cout << "[";
    for (auto k = list.begin(); k != list.end(); ++k) {
      std::cout << *k << " ";
    }
    std::cout << "]\n";
  }
  
  return list;
}

std::vector<int>& Sort::bubbleSort(std::vector<int>& list) {

  int n = list.size();
  size_t right = n - 1;
  bool noSwaps = true;

  while (right > 0) {
    bool noSwaps = true;
    for (size_t left = 0; left < right; left++) {
      if (list[left] > list[left + 1]) {
        std::swap(list[left], list[left + 1]);
        noSwaps = false;
      }      
    }
    if (noSwaps == true) {
      break;
    }
    right--;
  }
  return list;
}

std::vector<int>& Sort::mergeSort(std::vector<int>& list) {
  int end = list.size() - 1;
  int start = 0;
  merge(list, start, end);
 
  return list;
}

void Sort::merge(std::vector<int>& list, int start, int end) {
  if (start >= end) {
    return;
  }
  int mid = (start + end) / 2;
  int l = mid - start + 1;
  int r = end - mid;

  merge(list, start, mid);
  merge(list, mid + 1, end);

  std::vector<int> leftArr(l);
  std::vector<int> rightArr(r);

  for (int i = 0; i < l; i++) {
    leftArr[i] = list[start + i];
  }

  for (int i = 0; i < r; i++) {
    rightArr[i] = list[mid + i + 1];
  }
 
  int left = 0;
  int right = 0;
  int ptr = start;

  while (left < l && right < r) {
    if (leftArr[left] <= rightArr[right]) {
      list[ptr++] = leftArr[left++];
    } else {
      list[ptr++] = rightArr[right++];
    }
  }

  while (left < l) {
    list[ptr++] = leftArr[left++];
  }
  while (right < r) {
    list[ptr++] = rightArr[right++];
  }

}
std::vector<std::pair<int,char>>& Sort::mergeSortStable(std::vector<std::pair<int,char>>& list) {
  int end = list.size() - 1;
  int start = 0;
  mergeStable(list, start, end);

  return list;
}

void Sort::mergeStable(std::vector<std::pair<int,char>>& list, int start, int end) {
  if (start >= end) {
    return;
  }
  int mid = (start + end) / 2;
  int l = mid - start + 1;
  int r = end - mid;

  mergeStable(list, start, mid);
  mergeStable(list, mid + 1, end);

  std::vector<std::pair<int,char>> leftArr(l);
  std::vector<std::pair<int, char>> rightArr(r);

  for (int i = 0; i < l; i++) {
    leftArr[i] = list[start + i];
  }

  for (int i = 0; i < r; i++) {
    rightArr[i] = list[mid + i + 1];
  }

  int left = 0;
  int right = 0;
  int ptr = start;

  while (left < l && right < r) {
    if (leftArr[left].first <= rightArr[right].first) {
      list[ptr++] = leftArr[left++];
    } else {
      list[ptr++] = rightArr[right++];
    }
  }

  while (left < l) {
    list[ptr++] = leftArr[left++];
  }
  while (right < r) {
    list[ptr++] = rightArr[right++];
  }
}

void printPairList(std::vector<std::pair<int, char>> list) {
  std::cout << "(";
  for (auto i = list.begin(); i != list.end(); ++i) {
    std::cout << i->first << ", " << i->second << "), (";
  }
  std::cout << "\n";
}

std::vector<int>& Sort::quickSort(std::vector<int>& list) {
  int n = list.size();

  quickSortHelper(list, 0, n - 1);

  return list;

}

void Sort::quickSortHelper(std::vector<int>& list, int start, int end) {
  

  if (start >= end) {
    return;
  }
  int mid = (start + end) / 2;
  int top = list[end];
  int bottom = list[start];
  int middle = list[mid];
  int pivotChoice;
  if (top < std::max({middle, top, bottom}) && top > std::min({middle, top, bottom})) {
    pivotChoice = end;
  } else if (middle < std::max({middle, top, bottom}) && middle > std::min({middle, top, bottom})) {
    pivotChoice = mid;
  } else {
    pivotChoice = start;
  }  

  int pivot = list[pivotChoice];
  if (pivotChoice != end) {
    std::swap(list[pivotChoice], list[end]);
  }


  int pivotIndex = start;

  for (int index = start; index < end; index++) {
    if (list[index] < pivot) {
      std::swap(list[index], list[pivotIndex++]);
    }
  }
  std::swap(list[end], list[pivotIndex]);
  

  quickSortHelper(list, start, pivotIndex - 1);
  quickSortHelper(list, pivotIndex + 1, end);

}

std::vector<int> Sort::countingSort(std::vector<int>& list) {
  int min = list[0];
  int max = list[0];

  for (auto i = list.begin(); i != list.end(); ++i) {
    if (*i > max) {
      max = *i;
    }
    if (*i < min) {
      min = *i;
    } 
  }

  int range = (max - min) + 1;

  std::vector<int> count(range, 0);

  for (int i = 0; i < list.size(); i++) {
    count[list[i] - min]++;
  }
  
  int cumSum = 0;
  for (int i = 0; i < count.size(); i++) {
    if (count[i]) {
      int temp = count[i];
      count[i] += cumSum;
      cumSum += temp;
    }
    
  }
  
  std::vector<int> newList(list.size());
  for (int i = 0; i < list.size(); i++) {    
    newList[count[list[i] - min] - 1] = list[i];
    count[list[i] - min]--;
  }
  
  return newList;
}

int main() {
  srand(time(nullptr));
  int n = 10;
  std::vector<int> list(n);
  for (int i = 0; i < n; i++) {
    list[i] = (rand() % 20) + 1;
  }
  std::vector<std::pair<int, char>> list2(n);
  for (int i = 0; i < n; i++) {
    list2[i].first = (rand() % 5) + 1;
    list2[i].second = 'a' + rand() % 26;
  }
  Sort sorter;
  sorter.printList(list);
  std::vector<int> newList = sorter.countingSort(list);
  sorter.printList(newList);


  
}