#include <iostream>
#include <typeinfo>
#include <vector>
#include <list>

template<typename T>
class Allocator: public std::allocator<T> {
public:
  Allocator() throw() {
    std::cout << "Allocator() for " << typeid(T).name() << std::endl;
  }
  ~Allocator() throw() {
    std::cout << "~Allocator() for " << typeid(T).name() << std::endl;
  }
  template<typename U>
  Allocator(const Allocator<U>& other) {
    std::cout << "Allocator(cocnst ...) for " << typeid(U).name() << " and " << typeid(T).name() << std::endl;
  }

  template<typename U>
  struct rebind {
    typedef Allocator<U> other;
  };
};

int main() {
  std::list<int, Allocator<int> > v;
  v.push_back(123);
  return 0;
}
