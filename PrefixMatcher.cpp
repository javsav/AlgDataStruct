#include "PrefixMatcher.h"

int PrefixMatcher::selectRouter(std::string networkAddress) {
  return RouterDatabase.findRouter(networkAddress);
}

void PrefixMatcher::insert(std::string address, int routerNumber) {
  RouterDatabase.insertRouter(address, routerNumber);
}
