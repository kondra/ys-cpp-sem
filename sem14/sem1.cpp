#include <iostream>
#include <vector>

int main() {
  std::vector<int> v(10, 1);
  for (int &x: v) {
    ++x;
    std::cout << x << '\n';
  }
  return 0;
}
