#include <string>
#include "HashMap.h"

int main() {
  HashMap<std::string, int> hmap;
  std::string temp = "a";
  for (int i = 0; i < 10; i++) {
   temp += i + 'a';
   hmap.insert(temp, i);
   temp.pop_back();
  }
  
  hmap.printKeys();
  
  // Bucket<std::string, int>* table;
  // Bucket<std::string, int> buckets[30] {{}};
  // table = buckets;
  // std::string temp = "a";
  // for (int i = 0; i < 10; i++) {
  //   temp += i + 'a';
  //   table[i] = Bucket<std::string, int> (temp, i);
  //   temp.pop_back();
  // }

  // for (int i = 0; i < 10; i++) {
  //   std::cout << table[i].key << '\n';
  // }
}