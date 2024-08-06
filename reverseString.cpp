#include <iostream>
#include <string>

std::string reverseString(std::string str) {

  if (str.size() == 1) {
    return str;
  }
  std::string temp = str;
  temp.pop_back();
  return str[str.size() - 1] + reverseString(temp);
}

int main() {

  std::cout << reverseString("evian") << "\n";
}
