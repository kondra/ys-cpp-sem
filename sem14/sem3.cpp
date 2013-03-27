#include <vector>
#include <iostream>
#include <typeinfo>
#include <algorithm>

auto f()->int {
  return 0;
}

int main() {
  std::vector<int> v {1,2,3,5};
  auto a = 12;
  decltype(v[0]) b = a;
  std::cout << typeid(b).name() << std::endl;

  std::cout << f() << '\n';

  int sum = 0;
  std::for_each(v.begin(), v.end(), [&sum](int x)->int{sum += x; std::cout << x << '\n';return 1;});
  //[=] - все по значению
  //[&] - все по ссылке

  std::cout << "sum = " << sum << '\n';

  return 0;
}
