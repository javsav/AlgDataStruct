#include "Trie.h"

#include <string>

int fac(int n) {

if (n <= 1) {
return 1;
}

return n * fac(n - 1);
}

int fac2Helper(int n, int acc) {
  if (n <= 1) {
    return acc;
  }

  return fac2Helper(n - 1, n*acc);
}

int fac2(int n) {
  return fac2Helper(n, 1);
}

int cumSumHelper(int n, int acc) {
	
	if (n == 0) {
	return acc;
	}
	
	return cumSumHelper(n-1,n+acc);
	
	}
	
	int cumSum(int n) {
	return cumSumHelper(n, 0);
}

int main() {

  Trie<int> trie;
  trie.insert("apple");
  trie.insert("application");
  trie.insert("applet");
  trie.insert("beast");
  trie.insert("beastiality");
  trie.insert("z");

  trie.printAll();

  std::vector<std::string> words = trie.search("be");

  for (auto word:words) {
    std::cout << word << ' ';
  }
  std::cout << '\n';

  std::cout << trie["sd"] << '\n';

  std::cout << fac(5) << '\n';

  std::cout << cumSum(4);
  
  // std::string test = "a";
  // NodeData<int, std::string> datum(1, "aa");
  // tree.insert(datum);
  // NodeData<int, std::string> datum2(3, "aaa");
  // tree.insert(datum2);
// std::string test = "a";
//   for (int i = 0; i < 10; i++) {
//     test += + 'a';
//     NodeData<int, std::string> datum(i, test);
//     tree.insert(datum);
//     //tree.printAsTree();
//   }
// tree.printAsTree();
  // for (int i = 0; i < 10; i++) {
  //   //test += + 'a';
  //   //NodeData<int, std::string> datum(i, test);
  //   tree.insert(i);
  // }

  // tree.printAsTree();
  // tree.insert(11);
  // tree.printAsTree();
  // tree.insert(13);
  // std::cout << "\n";
  // tree.printAsTree();
}

//                  11B
//            6B       16B
//       2B         8B
//    1B  4B       7B  9B
// 3R 5R 10R 15R 18R 20B