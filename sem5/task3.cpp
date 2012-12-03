#include <iostream>
#include <algorithm>
#include <string>

int main() {
  std::string word;
  std::cin >> word;
  std::sort(word.begin(), word.end());
  std::cout << word << '\n';
  while (std::next_permutation(word.begin(), word.end())) {
    std::cout << word << '\n';
  }
  return 0;
}
