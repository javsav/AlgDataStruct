#include "Svector.cpp"
#include <iostream>

int main() {

  Svector<int, 10> array;

  array.push_back(3);
  array.push_back(20);
  array.push_back(22);
  array.push_back(420);
  array.push_back(69);
  array.push_back(37);
  array.insert(96);
  array.clear();

  

  for (int i = 0; i < 10; i++) {
    std::cout << "array[" << i << "]: " << array[i] << "\n";
  }
  
  return 0;

}