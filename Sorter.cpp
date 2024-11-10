#include "Sorter.h"
#include <iostream>
#include "Timer.h"

std::vector<int>& Sorter::insertionSort(std::vector<int>& list) {
  int n = list.size();

  int left = 0;

  while (left < n - 1) {
    int right = left + 1;
    int m = left;
    int value = list[right];
    while (m >= 0 && value < list[m]) {
      list[m + 1] = list[m];
      m--;
    }
    list[m + 1] = value;
    left++;
    
  } 
  
  return list;

}

std::vector<int>& Sorter::selectionSort(std::vector<int>& list) {
  int n = list.size();

  int left = 0;  
  while (left < n - 1) {
    int min = left;
    for (int right = left; right < n; right++) {      
      if (list[right] < list[min]) {
        min = right;
      }
    }    
    std::swap(list[min], list[left]);
    left++;    
  }
  return list;
}

std::vector<int>& Sorter::bubbleSort(std::vector<int>& list) {
  int right = list.size() - 1;

  int left = 0;

  while (right > 0) {
    for (int i = left; i < right; i++) {
      if (list[i] > list[i + 1]) {
        std::swap(list[i], list[i+1]);
      }
    }
    right--;
  }

  return list;
}


std::vector<int>& Sorter::quickSort(std::vector<int>& list) {
  int end = list.size() - 1;
  qSort(list, 0, end);
  return list;
}


void Sorter::qSort(std::vector<int>& list, int start, int end) {  
  if (start >= end) {
    return;
  }
  
  int pivot = list[end];
  
  
  
  int pivotIndex = start;

  for (int i = start; i < end; i++) {
    if (list[i] < pivot) {
      std::swap(list[i], list[pivotIndex]);
      pivotIndex++;
    }
  }
  std::swap(list[end], list[pivotIndex]);
 

  qSort(list, start, pivotIndex - 1);
  qSort(list, pivotIndex + 1, end);
  
}

std::vector<int>& Sorter::mergeSort(std::vector<int>& list) {
  int end = list.size() - 1;
  int start = 0;
  mSort(list, start, end);
  return list;
}

void Sorter::mSort(std::vector<int>& list, int start, int end) {
  if (start >= end) {
    return;
  }
  int mid = (start + end) / 2;
  mSort(list, start, mid);
  mSort(list, mid+1, end);
  int lSize = mid - start + 1;
  int rSize = end - mid;
  int left[lSize];
  int right[rSize];

  for (int i = 0; i < lSize; i++) {
    left[i] = list[i + start];
  }

  for (int i = 0; i < rSize; i++) {
    right[i] = list[i + mid + 1];
  }

  int l = 0;
  int r = 0;
  int p = 0;
  while (l < lSize && r < rSize) {
    if (left[l] <= right[r]) {
      list[start + l + r] = left[l];
      l++;
    } else {
      list[start + l + r] = right[r];
      r++;
    }
  }

  while (l < lSize) {
    list[start + l + r] = left[l];
    l++;
  }

  while (r < rSize) {
    list[start + l + r] = right[r];
    r++;
  }

}


size_t Sorter::left(size_t i) {
  return (i * 2) + 1;
}

size_t Sorter::right(size_t i) {
  return (i * 2) + 2;
}

std::vector<int>& Sorter::heapSort(std::vector<int>& list) {
  size_t i = list.size() / 2;
  size_t end = list.size();
  while (i >= 0) {
    heapifyDown(i, list, end);
    for (auto num: list) {
      std::cout << num << " ";
    }
    i--;
    std::cout << "\n";
  }

  int start = 0;
  while (end > 1) {
    std::swap(list[start], list[end - 1]);
    end--;
    heapifyDown(start, list, end);
  }

  return list;
}


void Sorter::heapifyDown(size_t i, std::vector<int>& list, size_t end) {
  if (i >= end) {
    return;
  }

  int max = i;

  int l = left(i);
  int r = right(i);

  if (l < end && list[l] > list[max]) {
    max = l;
  }
  if (r < end && list[r] > list[max]) {
    max = r;
  }
  if (max != i) {
    std::swap(list[i], list[max]);
    heapifyDown(max, list, end);
  }
}

int main() {
  Timer timer;
  std::vector<int> list = {4,8,7,9,6,5,2,1,5,7,9,6,5,2,1,5,6,5,2,1,5,7,9,4,7,9,4,4,5,7,9,3,6,6,5,2,1,5,7,9,4,5,44,2,1,5,4,9,8,7,6,5,4,8,4,6,5,7,9,8,5,4,8,4,5,7,77,66,4,8,7,9,6,5,2,1,5,7,9,6,5,2,1,5,6,5,2,1,5,7,9,4,7,9,4,4,5,7,9,3,6,6,5,2,1,5,7,9,4,5,44,2,1,5,4,9,8,7,6,5,4,8,4,6,5,7,9,8,5,4,8,4,5,7,77,66,4,8,7,9,6,5,2,1,5,7,9,6,5,2,1,5,6,5,2,1,5,7,9,4,7,9,4,4,5,7,9,3,6,6,5,2,1,5,7,9,4,5,44,2,1,5,4,9,8,7,6,5,4,8,4,6,5,7,9,8,5,4,8,4,5,7,77,66};
  
  std::vector<int> list2 = list;
  Sorter sorter;
  sorter.heapSort(list);
  int n = 10000;
  timer.startTimer();  
  for (int i = 0; i < n; i++) {
    sorter.quickSort(list);
    list = list2;
  }
  timer.stopTimer();
  std::cout << "QuickSort - Elapsed Time: " << timer.time().count() << " ms\n";
  list = list2;
  timer.startTimer();
  for (int i = 0; i < n; i++) {
    sorter.mergeSort(list);
    list = list2;
  }
  timer.stopTimer();
  std::cout << "MergeSort - Elapsed Time: " << timer.time().count() << " ms\n";
  list = list2;
  timer.startTimer();
  for (int i = 0; i < n; i++) {
    sorter.insertionSort(list);
    list = list2;
  }
  timer.stopTimer();
  std::cout << "InsertionSort - Elapsed Time: " << timer.time().count() << " ms\n";
  list = list2;
  timer.startTimer();
  for (int i = 0; i < n; i++) {
    sorter.bubbleSort(list);
    list = list2;
  }
  timer.stopTimer();
  std::cout << "BubbleSort - Elapsed Time: " << timer.time().count() << " ms\n";
  list = list2;
  timer.startTimer();
  for (int i = 0; i < n; i++) {
    sorter.selectionSort(list);
    list = list2;
  }
  timer.stopTimer();
  std::cout << "SelectionSort - Elapsed Time: " << timer.time().count() << " ms\n";
  list = list2;
  timer.startTimer();
  for (int i = 0; i < n; i++) {
    sorter.heapSort(list);
    list = list2;
  }
  timer.stopTimer();
  std::cout << "HeapSort - Elapsed Time: " << timer.time().count() << " ms\n";
}