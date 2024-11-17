#include "Bucket.h"
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <iterator>

template <typename T>
class Hash {

  private:
  static size_t hash(T key, int modulus);

template <typename keyType, typename dataType>
friend class HashMap;
};

template <typename T, typename U>
class HashMap {

 private:  
  int m_size = 0;
  int capacity = 30;
  Bucket<T, U>* table;  

 public:
  HashMap() {    
    table = new Bucket<T, U>[capacity];
    for (int i = 0; i < capacity; i++) {
      table[i] = Bucket<T,U>();
    }
  }

  void resize() {
    Bucket<T, U>* newTable = new Bucket<T, U>[capacity * 2];    
    std::copy(table, table+capacity, newTable);
    delete[] table;
    capacity *= 2;
    table = newTable;   
  }

  void insert(T key, U data) {
    size_t hash = Hash<T>::hash(key, capacity);    
    if (table[hash].full) {
      int powTwo = 2;
      hash = hash + 1;
      while (table[hash].full) {
        hash += powTwo;
        std::cout << hash << '\n';
        powTwo * 2;
      }
    }
    table[hash] = Bucket<T,U>(key, data);
    m_size++;
  }

  void hash(T key);
  void printIfFull() {
    for (int i = 0; i < capacity; i++) {
      std::cout << table[i].full << "\n";
    }
  }
     
  

  void printKeys() {
    for (int i = 0; i < capacity; i++) {
      if (table[i].full){
        std::cout << table[i].key << '\n';
      }
    }
  }

  int size() {
    return m_size;
  }





};

template <>
inline size_t Hash<std::string>::hash(std::string key, int modulus) {
  size_t hash = 1;
  int m = modulus - 8;
  int base = 13;
  int power = 1;
  for (int i = 0; i < key.size(); i++) {
    hash = (hash * key[i]);
    hash = (hash * power) % modulus;
    power *= base;
  }
  return hash;

}
