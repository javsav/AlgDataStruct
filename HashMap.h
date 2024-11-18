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
  int capacity = 60;
  Bucket<T, U>* table;  

 public:
  HashMap() {    
    table = new Bucket<T, U>[capacity];
    for (int i = 0; i < capacity; i++) {
      table[i] = Bucket<T,U>();
    }
  }

  inline void rehash(T key, U data, Bucket<T, U>* newTable) {
    size_t hash = Hash<T>::hash(key, capacity);
    if (newTable[hash].full) {
      hash = hash + 1;
      while (newTable[hash].full) {
        hash += 1;
        // Bounds checking **
      }
    }
    newTable[hash] = Bucket<T, U>(key, data);    
  }

  U search(T key) {
    size_t hash = Hash<T>::hash(key, capacity);
    if (table[hash].full) {
      if (table[hash].key == key) {        
        return table[hash].data;
      } else {
        hash++;
        while (table[hash].full) {
          if (table[hash].key == key) {
            return table[hash].data;
          } else {
            hash++;
          }
        }
      }
    } else {      
      return U();
    }
    return U();
  }

  void remove(T key) {
    size_t hash = Hash<T>::hash(key, capacity);
    if (table[hash].full) {
      if (table[hash].key == key) {
        table[hash].deletedKey = key;
        table[hash].full = false;
        return;
      } else {
        hash++;
        while (table[hash].full) {
          if (table[hash].key == key) {
            table[hash].deletedKey = key;
            table[hash].full = false;
            return;
          } else {
            hash++;
          }
      }
    }
  } else {
    return;
  }

  }

  void resize() {
    Bucket<T, U>* newTable = new Bucket<T, U>[capacity * 2];    
    for (int i = 0; i < capacity; i++) {
      if (table[i].full) {
        rehash(table[i].key, table[i].data, newTable);
      }
    }
    delete[] table;
    capacity *= 2;
    table = newTable;   
  }

  void insert(T key, U data) {
    double load = (double)m_size / (double)capacity;
    if (load >= 0.7) {
      resize();
    }
    size_t hash = Hash<T>::hash(key, capacity);    
    if (table[hash].full) {      
      hash = hash + 1;
      while (table[hash].full) {
        hash += 1;
        if (hash >= capacity) {
          resize();
          return insert(key, data);
        }        
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
  int base = 53;
  int m = modulus * 0.7;
  int power = 1;
  for (int i = 0; i < key.size(); i++) {
    hash = (hash * key[i] - 'a' + 1);
    hash = (hash * power) % m;
    power = (power * base) % m;
  }
  return hash;

}
