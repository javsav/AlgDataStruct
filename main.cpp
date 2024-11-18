#include <string>
#include "HashMap.h"

int main() {
  HashMap<std::string, int> hmap;
  hmap.insert("fig", 12);
  hmap.insert("pussy", 69);
  hmap.insert("anus", 100);
  
  hmap.printKeys();
  std::cout << hmap.size() << "\n";
  std::cout << hmap.search("pussy") << "\n";
  
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