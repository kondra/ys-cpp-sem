#include <iostream>
#include <functional>
#include <iterator>
#include <algorithm>

struct logical_xor: public std::binary_function<bool, bool, bool> {
  bool operator()(bool a, bool b) const {
    if (a == b) {
      return false;
    } else {
      return true;
    }
  }
};

int main() {
  bool a[] = {true, false, false, true, true, false};
  std::transform(a, a + 6, std::ostream_iterator<int>(std::cout, " "), std::bind2nd(logical_xor(), true));
  std::cout << '\n';
  return 0;
}
