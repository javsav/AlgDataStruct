#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include "Trie.h"

class PrefixMatcher {

 private:
  Trie<int> RouterDatabase;

 public:
  int selectRouter(std::string networkAddress);
  void insert(std::string address, int routerNumber);
};

#endif // PREFIXMATCHER_H