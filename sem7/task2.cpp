#include <iostream>
#include <functional>
#include <iterator>
#include <string>
#include <algorithm>

template<typename Functor1, typename Functor2>
struct composer {
  typedef typename Functor1::result_type result_type;
  typedef typename Functor2::argument_type argument_type;

  Functor1 f_first;
  Functor2 f_second;

  composer(Functor1 f_first, Functor2 f_second) :
    f_first(f_first),
    f_second(f_second) {
  }

  result_type operator()(argument_type x) {
    return f_first(f_second(x));
  }
};

template<typename Functor1, typename Functor2>
composer<Functor1, Functor2> compose(Functor1 f_first, Functor2 f_second) {
  return composer<Functor1, Functor2>(f_first, f_second);
}

int main() {
  std::string s[] = {"1.21", "0.42", "3.14", "2.71", "0.0001", "1e-10", "123"};
  std::transform(s, s + 7, std::ostream_iterator<double>(std::cout, " "), compose(std::ptr_fun(atof), std::mem_fun_ref(&std::string::c_str)));
  std::cout << '\n';
  return 0;
}
