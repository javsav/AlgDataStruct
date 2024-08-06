#include <iostream>
#include <string>

int isPalindrome(std::string str) {
  if (str[0] != str[str.size() - 1]) {
    return 0;
  }
  if (str.size() == 1 || str.size() == 2) {
    return 1;
  }
  str.erase(0, 1);
  str.pop_back();
  return isPalindrome(str);
}

int main() {

  std::cout << isPalindrome("racecar") << "\n";
}
