#include "Finder.h"

    

    std::vector<int> Finder::findSubstrings(std::string s1, std::string s2) {

        std::vector<int> result(s2.size(), -1);
        size_t lastIndex = 0;

        for(size_t i = 0; i <= s2.size() - 1; i++) {
          for (size_t j = lastIndex; lastIndex < s1.size(); lastIndex++) {
              if (s1[j] == s2[i]) {
                for (size_t k = 0; k < i + 1; k++) {
                  if (!s1[k + j] == s2[k]) {
                    break;
                  }
                }
                result[i] = j;
                lastIndex = j;
                break;
              }              
          }
        }
        return result;
    }

   