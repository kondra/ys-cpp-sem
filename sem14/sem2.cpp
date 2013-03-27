#include <iostream>
#include <vector>

struct S {
  int a;
  double b;
};

int main() {
  S s = {1, 2.71};
  S arr[] = {{1, 2.0}, {3, 4.0}};
  int a[] = {1, 2, 3};
  //initializer list
  std::vector<int> v = {1, 2, 3};
  std::vector<int> v1{1, 2, 3};

  for (int& x: v1) {
    std::cout << x << ' ';
  }
  std::cout << '\n';

  for (int x: {1,2,3,4,5}) {
    std::cout << x << ' ';
  }
  std::cout << '\n';

  return 0;
}
