#include <string>
#include <vector>
#include <iostream>

// Parameters for the rolling hash function
const int BASE = 256;        // Assuming ASCII characters
const int MOD = 1000000007;  // A large prime number to reduce collisions

// Compute the hash value of a string
long long computeHash(const std::string& str) {
  long long hashValue = 0;
  long long power = 1;
  for (char ch : str) {
    hashValue = (hashValue + ch * power) % MOD;
    power = (power * BASE) % MOD;
  }
  return hashValue;
}

// Rabin-Karp search algorithm for prefixes
std::vector<int> RabinKarpSearch(const std::string& text,
                                 const std::string& pattern) {
  int N = text.size();
  int M = pattern.size();

  // Precompute hash values for all prefixes of the pattern
  std::vector<long long> patternHashes(M + 1);
  patternHashes[0] = 0;  // Empty prefix
  for (int i = 1; i <= M; i++) {
    patternHashes[i] = computeHash(pattern.substr(0, i));
  }

  std::vector<int> result(M, -1);  // Initialize with -1

  
  for (int stringLength = 1; stringLength < pattern.size(); stringLength++) {
    long long textHash = 0;
    long long power = 1;
    for (int i = 0; i < stringLength - 1; i++) {
      textHash = (textHash + text[i] * power) % MOD;
      power = (power * BASE) % MOD;
    }
  for (int i = 0; i <= N - M; i++) {
    // Add the new character and remove the old one from the rolling hash
    textHash = (textHash + text[i + M - 1] * power) % MOD;
    if (i > 0) {
      textHash = (textHash - text[i - 1] + MOD) % MOD;
      textHash = (textHash * BASE) % MOD;
    }

    // Compare with prefix hashes
    for (int j = 1; j <= M; j++) {
      std::cout << "textHash: " << textHash << ", PatternHashes[j]: " << patternHashes[j] << "\n";
      if (textHash == patternHashes[j]) {
        // Potential match, perform full string comparison to confirm
        if (text.substr(i, j) == pattern.substr(0, j)) {
          result[j - 1] = i;
        }
      }
    }
  }
  }
  return result;
}

int main() {
  std::string str1 = "1128221288128212821";
  std::string str2 = "12821";

  std::vector<int> answer = RabinKarpSearch(str1, str2);

  for (auto str : answer) {
    std::cout << str << "\n";
  }
}