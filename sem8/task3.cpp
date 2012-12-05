#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

size_t compute_shift(const std::string& str) {
  if (str.length() <= 2) {
    return 1;
  } else if (str.length() <= 5) {
    return 1;
  } else if (str.length() <= 7) {
    return 2;
  } else {
    return 3;
  }
}

int main() {
  std::vector<std::string> words;
  std::string tmp;

  while (std::cin >> tmp) {
    words.push_back(tmp);
  }

  size_t shift;

  for (size_t i = 0; i < words.size(); ++i) {
    tmp = words[i];
    shift = compute_shift(tmp);
    std::random_shuffle(tmp.begin() + shift, tmp.end() - shift);
    std::cout << tmp << ' ';
  }
  std::cout << '\n';

  for (size_t i = 0; i < words.size(); ++i) {
    tmp = words[i];
    shift = compute_shift(tmp);
    std::sort(tmp.begin() + shift, tmp.end() - shift);
    std::cout << tmp << ' ';
  }
  std::cout << '\n';

  return 0;
}
