#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>

template<typename C>
void print(const C& cont) {
  for (size_t i = 0; i != cont.size(); ++i) {
    std::cout << cont[i] << ' ';
  }
  std::cout << '\n';
}

template<typename C>
void print_iter(const C& cont) {
  for (typename C::const_iterator it = cont.begin(); it != cont.end(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << '\n';
}

template<typename T>
void print_element(const T& elem) {
  std::cout << elem << ' ';
}

template<typename Iter, typename F>
void for_each(Iter a, Iter b, F f) {
  while (a != b) {
    f(*a);
    ++a;
  }
}

template<typename T>
struct printElemFunctor {
  void operator () (const T& elem) const {
    std::cout << elem << ' ';
  }
};

template<typename C>
void print_3(const C& cont) {
  ::for_each(cont.begin(), cont.end(), printElemFunctor<typename C::value_type>());
  std::cout << '\n';
}

template<typename C>
void print_4(const C& cont) {
  std::copy(cont.begin(), cont.end(), std::ostream_iterator<typename C::value_type>(std::cout, ", "));
  std::cout << '\n';
}

int main() {
  /*
  std::deque<int> d(10);

  for (size_t i = 0; i != 10; ++i) {
    d[i] = i;
  }
  */

  //как декларация функции!
  std::deque<int> d (
      std::istream_iterator<int>(cin),
      std::istream_iterator<int>()
  );
  //OK!
  std::deque<int> d (
      std::istream_iterator<int>(std::cin),
      std::istream_iterator<int>()
  );
  //аналогично
  T t;
  T t();

  std::deque<int> d;
  std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::back_inserter(d));
  std::copy(d.begin(), d.end(), std::ostream_iterator<int>(std::cout, ", "));

  /*
  print(d);
  print_iter(d);
  print_3(d);
  print_4(d);
  */

  return 0;
}
