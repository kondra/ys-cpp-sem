#include <iostream>
#include <vector>
#include <string>
#include <deque>

template<typename T, template <typename T, typename=std::allocator<T> > class V>
class Wrapper {
  private:
    V<T>& data_;
  public:
    Wrapper(V<T>& data) : data_(data) {
    }
    const T& operator [] (size_t index) const {
      static T def = T();
      if (index < data_.size()) {
        return data_[index];
      }
      return def;
    }
    T& operator [] (size_t index) {
      if (index < data_.size()) {
        return data_[index];
      }
      data_.resize(index + 1);
      return data_[index];
    }
};

int main() {
  std::vector<int> v(10, 1);
  Wrapper<int, std::vector> vec(v);
  vec[2] = -1;
  vec[20] = -1;
  for (size_t i = 0; i < v.size(); ++i) {
    std::cout << v[i] << ' ';
  }
  std::cout << '\n';

  std::deque<int> d(10, 1);
  Wrapper<int, std::deque> dd(d);
  dd[20] = -1;
  for (size_t i = 0; i < d.size(); ++i) {
    std::cout << d[i] << ' ';
  }
  std::cout << '\n';

  const Wrapper<int, std::vector> cv(v);
  std::cout << cv[200] << '\n';

  return 0;
}
