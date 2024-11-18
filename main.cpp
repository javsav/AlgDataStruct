#include <string>
#include "HashMap.h"
#include "Timer.h"
#include <unordered_map>

int main() {

  Timer timer;
  timer.startTimer();
  for (int i = 0; i < 100; i++) {
  HashMap<std::string, int> hmap;
  std::string temp = "h";
  
  for (int i = 0; i < 200; i++) {
    temp += i + 'a';    
    hmap.insert(temp, i+23);
    temp.pop_back();
  }

  temp = "h";
  for (int i = 0; i < 200; i++) {
    temp += i + 'a';
    int b = hmap.search(temp);
    temp.pop_back();
  }
}
  timer.stopTimer();
  std::cout << timer.time().count() << " ms\n";

  Timer newtimer;
  newtimer.startTimer();
  for (int i = 0; i < 100; i++) {
    std::unordered_map<std::string, int> hmap;
    std::string temp = "h";

    for (int i = 0; i < 200; i++) {
      temp += i + 'a';
      hmap[temp] = i + 23;
      temp.pop_back();
    }

    temp = "h";
    for (int i = 0; i < 200; i++) {
      temp += i + 'a';
      int a = hmap[temp];
      temp.pop_back();
    }
  }
  newtimer.stopTimer();
  std::cout << newtimer.time().count() << " ms\n";

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