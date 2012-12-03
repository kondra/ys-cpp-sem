#include <iostream>
#include <vector>
#include <cassert>

template<typename Iter>
Iter unique(Iter first, Iter last) {
  Iter right = first, left = first;
  while (left != last) {
    ++right;
    while (right != last && *left == *right) {
      ++right;
    }
    *first = *left;
    ++first;
    left = right;
  }
  return first;
}

int main() {
  std::vector<int> v;
  v.push_back(2);
  v.push_back(2);
  v.push_back(2);
  v.push_back(1);
  v.push_back(1);
  v.push_back(2);
  v.push_back(2);
  v.push_back(4);
  v.push_back(4);
  v.push_back(4);
  std::vector<int>::iterator end = unique(v.begin(), v.end());
  for (std::vector<int>::iterator it = v.begin(); it != end; ++it) {
    std::cout << *it << ' ';
  }
  std::cout << '\n';

  std::vector<int> v2(1, 1);
  end = unique(v2.begin(), v2.end());
  assert(end == v2.end());
  for (std::vector<int>::iterator it = v2.begin(); it != end; ++it) {
    std::cout << *it << ' ';
  }
  std::cout << '\n';
  end = unique(v2.begin(), v2.begin());
  return 0;
}
