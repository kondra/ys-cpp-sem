#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <list>

template<typename Iter, typename Category>
void bd_sort_impl(Iter begin, Iter end, Category) {
  std::vector<typename Iter::value_type> buffer(begin, end);
  std::sort(buffer.begin(), buffer.end());
  typename std::vector<typename Iter::value_type>::iterator buffer_begin = buffer.begin();
  while (begin != end) {
    *begin = *buffer_begin;
    ++begin;
    ++buffer_begin;
  }
}

template<typename Iter>
void bd_sort_impl(Iter begin, Iter end, std::random_access_iterator_tag) {
  std::sort(begin, end);
}

template<typename Iter>
void bd_sort(Iter begin, Iter end) {
  bd_sort_impl(begin, end, typename std::iterator_traits<Iter>::iterator_category());
}

int main() {
  int array[7] = {10, 6, 3, 2, 4, 7, 9};
  std::vector<int> v(array, array + 7);
  std::list<int> l(array, array + 7);
  bd_sort(array, array + 7);
  bd_sort(v.begin(), v.end());
  bd_sort(l.begin(), l.end());
  std::cout << "array:\n";
  for (size_t i = 0; i < 7; ++i) {
    std::cout << array[i] << ' ';
  }
  std::cout << '\n';
  std::cout << "list:\n";
  for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << '\n';
  std::cout << "vector:\n";
  for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << '\n';
  return 0;
}
